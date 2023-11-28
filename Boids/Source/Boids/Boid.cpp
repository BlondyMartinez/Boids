// Fill out your copyright notice in the Description page of Project Settings.


#include "Boid.h"
#include "BoidManager.h"
#include "DrawDebugHelpers.h"

// Sets default values
ABoid::ABoid()
{
	// create root component
	root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(root);

	// create static mesh component
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cone"));
	UStaticMesh* sphereMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cone.cone'")).Object;
	mesh->SetStaticMesh(sphereMesh);
	mesh->AttachToComponent(root, FAttachmentTransformRules::KeepRelativeTransform);

	// set initial rotation of the mesh
	mesh->SetRelativeRotation(FRotator(270, 0, 0));
}

// calculate vector pointing towards a given position
FVector ABoid::Seek(FVector pos)
{
	FVector newVelocity = pos - GetActorLocation();
	newVelocity.Normalize();
	return newVelocity;
}

// calculate vector pointing away from given position
FVector ABoid::Flee(FVector pos)
{
	FVector newVelocity = GetActorLocation() - pos;
	newVelocity.Normalize();
	return newVelocity;
}

// calculate separation based on neighbours positions
FVector ABoid::Separation(TArray<ABoid*> neighbours)
{
	if (neighbours.Num() == 0) return FVector::ZeroVector;

	FVector avgFlee;

	for (ABoid* boid : neighbours) {
		avgFlee += Flee(boid->GetActorLocation());
	}

	avgFlee.Normalize();

	return avgFlee;
}

// calculate cohesion based on neighbours positions
FVector ABoid::Cohesion(TArray<ABoid*> neighbours)
{
	if (neighbours.Num() == 0) return FVector::ZeroVector;

	FVector avgPos;
	float inverse = 1 / neighbours.Num();

	for (ABoid* boid : neighbours) {
		avgPos += boid->GetActorLocation() * inverse;
	}

	return Seek(avgPos);
}

// calculate alignment vector based on neighbours velocities
FVector ABoid::Alignment(TArray<ABoid*> neighbours)
{
	if (neighbours.Num() == 0) return FVector::ZeroVector;

	FVector newVelocity;
	for (ABoid* boid : neighbours) {
		newVelocity += boid->currentVelocity;
	}

	newVelocity /= neighbours.Num();
	newVelocity.Normalize();

	return newVelocity;
}

// add random wander vector
FVector ABoid::Wander(float radius, float distance, float jitter)
{
//	angle += FMath::FRandRange(-1.f, 1.f) * variability;
//
//	// calculate x and y coordinates of a point in the unit circle
//	FVector circlePoint = FVector(FMath::Cos(angle), FMath::Sin(angle), 0);
//
//	FVector wanderTarget = GetActorLocation() + GetActorForwardVector() * distance * circlePoint * radius;
//
//	// displacement to add more randomness
//	FVector displacement = FVector(FMath::FRandRange(-1.f, 1.f), FMath::FRandRange(-1.f, 1.f), FMath::FRandRange(-1.f, 1.f)) * radius;
//	wanderTarget += displacement;
//	wanderTarget -= GetActorLocation();
//
//	return wanderTarget.GetSafeNormal();

		FVector currentPos = GetActorLocation();

		if (FVector::Dist(currentPos, wanderDestination) < 100) {
			FVector projectedPos = currentPos + (GetActorForwardVector() * distance);

			wanderDestination = projectedPos + (FMath::VRand() * FMath::RandRange(0.f, jitter));
		}

		FVector jitterDestination = Seek(wanderDestination) + (FMath::VRand() * FMath::RandRange(0.f, jitter));

		return jitterDestination;
	
}

// called from BoidManager to update boid behavior
void ABoid::UpdateBoid(float DeltaTime)
{
	FVector targetVelocity = FVector::ZeroVector;

	ApplyContainment();

	TArray<ABoid*> closestBoids = manager->GetBoidNeighbourhood(this);

	// apply forces
	targetVelocity += Separation(closestBoids) * manager->separationWeight();
	targetVelocity += Cohesion(closestBoids) * manager->cohesionWeight();
	targetVelocity += Alignment(closestBoids) * manager->alignmentWeight();

	targetVelocity.Normalize();

	// if velocity is small add wandering behavior
	if (targetVelocity.Size() < 1) {
		targetVelocity += Wander(100, 200, 1);
		targetVelocity.Normalize();
	}

	FVector newForce = targetVelocity - currentVelocity;
	currentVelocity += newForce * DeltaTime;

	// draw line to see current velocity
	FVector LineStart = GetActorLocation();
	FVector LineEnd = LineStart + currentVelocity.GetSafeNormal() * 100.0f; 
	DrawDebugLine(GetWorld(), LineStart, LineEnd, FColor::Green, false, -1, 0, 1);

	// update position
	FVector location = GetActorLocation();
	location += currentVelocity * speed * DeltaTime;

	// rotate root component to align with direction
	FVector coneDirection = currentVelocity.GetSafeNormal();
	root->SetWorldRotation(coneDirection.Rotation());

	SetActorLocation(location);
}

// called from boidmanager to set the material of the cone
void ABoid::SetConeMaterial(UMaterialInterface* material)
{
	mesh->SetMaterial(0, material);
}

// apply containment force to keep boids within sphere
void ABoid::ApplyContainment()
{
	FVector toCentre = manager->sphereCentre - GetActorLocation();
	float distance = toCentre.Size();

	if (distance > manager->sphereRadius) {
		FVector correction = toCentre.GetSafeNormal() * (distance - manager->sphereRadius);
		currentVelocity += correction * manager->containmentForce();
	}
}