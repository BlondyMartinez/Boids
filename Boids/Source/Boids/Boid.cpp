// Fill out your copyright notice in the Description page of Project Settings.


#include "Boid.h"
#include "BoidManager.h"
#include "BoidManagerParameters.h"
#include "DrawDebugHelpers.h"
#include "NiagaraComponent.h"
#include "Predator.h"
#include "GridActor.h"

// Sets default values
ABoid::ABoid()
{
	// create root component
	root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(root);

	// create and attach static mesh component
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cone"));
	UStaticMesh* coneMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cone.cone'")).Object;
	mesh->SetStaticMesh(coneMesh);
	mesh->AttachToComponent(root, FAttachmentTransformRules::KeepRelativeTransform);

	// set relative rotation of the mesh so the tip of the cone faces the direction its moving towards
	mesh->SetRelativeRotation(FRotator(270, 0, 0));

	// create and attach ribbon 
	ribbon = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Ribbon"));
	ribbon->AttachToComponent(root, FAttachmentTransformRules::KeepRelativeTransform);
}

// called from BoidManager 
void ABoid::UpdateBoid(float DeltaTime)
{
	FVector targetVelocity = ApplyContainment();

	GetNearbyEntities();

	FVector avoidance = ObstacleAvoidance(manager->GetNearbyObstacles(this));
	targetVelocity += avoidance;

	FVector evasion = Evade(nearbyPredators);
	targetVelocity += evasion;

	targetVelocity += Separation(nearbyBoids) * parameters->separationWeight;
	// slightly bigger cohesion weight if in danger
	if (inDanger) targetVelocity += Cohesion(nearbyBoids) * (parameters->cohesionWeight + .25f);
	else targetVelocity += Cohesion(nearbyBoids) * parameters->cohesionWeight;

	targetVelocity += Alignment(nearbyBoids) * parameters->alignmentWeight;
	if (parameters->colorBias) targetVelocity += Repulsion(nearbyBoids);

	targetVelocity.Normalize();

	if (targetVelocity.Size() < 1) {
		targetVelocity += Wander(200, 50);
		targetVelocity.Normalize();
	}

	// calculate acceleration
	FVector force = targetVelocity * speed - currentVelocity;
	FVector acceleration = force * massInverse; // F = ma


	// update velocity and pos
	currentVelocity += acceleration * DeltaTime;
	FVector location = GetActorLocation() + currentVelocity * DeltaTime;

	SetActorLocation(location);

	// rotate root component to align with direction
	FVector coneDirection = currentVelocity.GetSafeNormal();
	root->SetWorldRotation(coneDirection.Rotation());
}

//  BEHAVIOR STUFF 

// calculate vector pointing towards a given position
FVector ABoid::Seek(const FVector& pos)
{
	FVector newVelocity = pos - GetActorLocation();
	newVelocity.Normalize();
	return newVelocity;
}

// calculate vector pointing away from given position
FVector ABoid::Flee(const FVector& pos)
{
	FVector newVelocity = GetActorLocation() - pos;
	newVelocity.Normalize();
	return newVelocity;
}

// calculate separation based on neighbours positions
FVector ABoid::Separation(const TArray<ABoid*>& neighbours)
{
	if (neighbours.Num() == 0) return FVector::ZeroVector;

	FVector separationForce;
	float minDistance = FLT_MAX; // minDistance = huge value

	for (ABoid* boid : neighbours) {
		float distance = FVector::Dist(GetActorLocation(), boid->GetActorLocation());
		FVector fleeForce = Flee(boid->GetActorLocation());

		// weight by inverse distance
		fleeForce *= 1 / FMath::Max(distance, 1.0f);
		separationForce += fleeForce;

		if (distance < minDistance) {
			minDistance = distance;
		}
	}

	// 110 being the boid diameter plus 10
	if (minDistance < 110) {
		separationForce *= FMath::Lerp(5, 1.0f, minDistance / 110);
	}

	return separationForce;
}

// calculate cohesion based on neighbours positions
FVector ABoid::Cohesion(const TArray<ABoid*>& neighbours)
{
	if (neighbours.Num() == 0) return FVector::ZeroVector;

	FVector avgPos;
	int count = 0;

	for (ABoid* boid : neighbours) {
		// if there's no color bias OR if there is and they are the same color
		if (!parameters->colorBias || (parameters->colorBias && boid->color == this->color)) {
			avgPos += boid->GetActorLocation();
			count++;
		}
	}
	
	if (count != 0) avgPos /= count;

	return Seek(avgPos);
}

// calculate alignment vector based on neighbours velocities
FVector ABoid::Alignment(const TArray<ABoid*>& neighbours)
{
	if (neighbours.Num() == 0) return FVector::ZeroVector;

	FVector newVelocity;
	int count = 0;

	for (ABoid* boid : neighbours) {
		// if there's no color bias OR if there is and they are the same color
		if (!parameters->colorBias || (parameters->colorBias && boid->color == this->color)) {
			newVelocity += boid->currentVelocity;
			count++;
		}
	}

	if (count != 0) newVelocity /= count;
	newVelocity.Normalize();

	return newVelocity;
}

FVector ABoid::Wander(float distance, float jitter)
{
	FVector currentPos = GetActorLocation();

	// calculate random destination
	FVector projectedPos = currentPos + (GetActorForwardVector() * distance);
	FVector randomOffset = FMath::VRand() * jitter;
	FVector newTarget = projectedPos + randomOffset;

	// interpolate towards the new target
	wanderDestination = FMath::Lerp(wanderDestination, newTarget, .5f);

	return Seek(wanderDestination);
}

FVector ABoid::ApplyContainment()
{
	FVector toCentre = manager->sphereCentre - GetActorLocation();
	float distance = toCentre.Size();

	if (distance > manager->sphereRadius) {
		// soft boundary
		float force = FMath::Clamp((distance - manager->sphereRadius) / 500, 0, 1);
		FVector correction = toCentre.GetSafeNormal() * (distance - manager->sphereRadius);
		return correction * force * parameters->containmentForce;
	}

	return FVector::ZeroVector;
}

// repulsion by color difference
FVector ABoid::Repulsion(const TArray<ABoid*>& neighbours)
{
	FVector repulsion = FVector::ZeroVector;

	for (ABoid* boid : neighbours) {
		// if different color and too close boid gets repulsed
		if (boid->color != color) {
			FVector toBoid = boid->GetActorLocation() - GetActorLocation();
			float distance = toBoid.Size();

			if (distance < 500) {
				FVector repulsionDirection = -toBoid.GetSafeNormal();
				float force = FMath::Clamp((500 - distance) / 500, 0, 1);
				repulsion += repulsionDirection * force * parameters->repulsionForce;
			}
		}
	}

	return repulsion;
}

// avoid obstacles if nearby
FVector ABoid::ObstacleAvoidance(const TArray<AActor*>& obstacles)
{
	FVector avoidance = FVector::ZeroVector;

	for (AActor* obstacle : obstacles) {
		FVector toObstacle = obstacle->GetActorLocation() - GetActorLocation();
		float distance = toObstacle.Size();
		float obstacleRadius = obstacle->GetActorScale3D().X * 100 * .5f;

		if (distance < parameters->neighbourhoodRadius + obstacleRadius) {
			FVector avoidanceDirection = -toObstacle.GetSafeNormal();
			float avoidanceStrength = FMath::Clamp(1.0f - (distance / (parameters->neighbourhoodRadius + obstacleRadius)), 0.0f, 1.0f);
			avoidance += avoidanceDirection * avoidanceStrength * parameters->obstacleAvoidanceForce;
		}
	}

	return avoidance;
}

FVector ABoid::Evade(const TArray<APredator*>& predators)
{
	FVector evasionVelocity = FVector::ZeroVector;
	int predatorCount = 0;

	for (APredator* predator : predators) {
		FVector toPredator = predator->GetActorLocation() - GetActorLocation();
		float distance = toPredator.Size();

		if (distance < (parameters->neighbourhoodRadius + 150) && distance > 100) {
			// predict future position of predator
			float predictionTime = distance / parameters->predatorSpeed;
			FVector futurePos = predator->GetActorLocation() + predator->currentVelocity * predictionTime * 5;

			// flee from futurepos
			evasionVelocity = GetActorLocation() - futurePos;

			predatorCount++;
		}
		else if (distance < 100) {
			KillBoid();
			return FVector::ZeroVector;
		}
	}

	if (predatorCount > 0) {
		evasionVelocity /= predatorCount;
		evasionVelocity.Normalize();
	}

	return evasionVelocity;
}

void ABoid::GetNearbyEntities()
{
	// clear arrays
	nearbyBoids.Empty();
	nearbyPredators.Empty();

	inDanger = false;
	Saturate(0);

	// get cell index and adjacent indices
	FVector pos = GetActorLocation();
	int currentCellIndex = grid->GetCellIndex(pos);

	TArray<int> adjacentCellIndices = grid->GetAdjacentCellIndices(currentCellIndex);

	// add current cell stuff

	for (ABoid* boid : grid->GetBoidsInCell(currentCellIndex)) {
		if (boid == this || !IsValid(boid)) continue;

		float distance = (GetActorLocation() - boid->GetActorLocation()).Size();
		if (distance < parameters->neighbourhoodRadius) {
			nearbyBoids.Add(boid);
		}
	}

	for (APredator* predator : grid->GetPredatorsInCell(currentCellIndex)) {
		if (!nearbyPredators.Contains(predator) && IsValid(predator)) AddPredator(predator);
	}

	// add adjacent cells stuff
	for (int cellIndex : adjacentCellIndices) {
		for (ABoid* boid : grid->GetBoidsInCell(cellIndex)) {
			if (!nearbyBoids.Contains(boid) && boid != this && IsValid(boid)) {
				float distance = (GetActorLocation() - boid->GetActorLocation()).Size(); 
				if (distance < parameters->neighbourhoodRadius) {
					nearbyBoids.Add(boid);
				}
			}
		}

		for (APredator* predator : grid->GetPredatorsInCell(cellIndex)) {
			if (!nearbyPredators.Contains(predator) && IsValid(predator)) AddPredator(predator);
		}
	} 
}

// distance check for predators
void ABoid::AddPredator(APredator* predator)
{
	float distance = (GetActorLocation() - predator->GetActorLocation()).Size();
	if (distance < parameters->neighbourhoodRadius + 150) {
		inDanger = true;
		Saturate(-.5f);
		nearbyPredators.Add(predator);
	}
}

void ABoid::Saturate(float saturationMultiplier)
{
	mat->SetScalarParameterValue(FName ("DesaturationMultiplier"), saturationMultiplier);
	mesh->SetMaterial(0, mat);
}

void ABoid::KillBoid()
{
	manager->boidsToRemove.Add(this);
}

// stuff called from boidmanager

void ABoid::SetConeMaterial(UMaterialInterface* material)
{
	mat = UMaterialInstanceDynamic::Create(material, this);
	mesh->SetMaterial(0, mat);
}

void ABoid::SetConeScale(float aMass)
{
	mass = aMass;
	massInverse = 1 / mass;
	mesh->SetWorldScale3D(FVector(mass));
}

void ABoid::AssignRibbonToComponent(UNiagaraSystem* ribbonSystem)
{
	ribbon->SetAsset(ribbonSystem);
}

