// Fill out your copyright notice in the Description page of Project Settings.


#include "Boid.h"
#include "BoidManager.h"
#include "BoidManagerParameters.h"
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

	// set relative rotation of the mesh so the tip of the cone faces the direction its moving towards
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

	// adjust magnitude based on proximity of the closest neighbor
	// 110 being the boid diameter plus 10
	if (minDistance < 110) {
		separationForce *= FMath::Lerp(5, 1.0f, minDistance / 110);
	}

	return separationForce;
}

// calculate cohesion based on neighbours positions
FVector ABoid::Cohesion(TArray<ABoid*> neighbours)
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

// TODO watch tutorial again or get rid of radius as its not used
FVector ABoid::Wander(float radius, float distance, float jitter)
{
	FVector currentPos = GetActorLocation();

	if (FVector::Dist(currentPos, wanderDestination) < 100) {
		FVector projectedPos = currentPos + (GetActorForwardVector() * distance);

		wanderDestination = projectedPos + (FMath::VRand() * FMath::RandRange(0.f, jitter));
	}

	FVector jitterDestination = Seek(wanderDestination) + (FMath::VRand() * FMath::RandRange(0.f, jitter));

	return jitterDestination;
	
}

// called from BoidManager 
void ABoid::UpdateBoid(float DeltaTime)
{
	FVector targetVelocity = FVector::ZeroVector;

	// apply containment
	FVector containmentForce = ApplyContainment();
	if (!containmentForce.IsZero()) {
		targetVelocity += containmentForce;
	}

	TArray<ABoid*> closestBoids = manager->GetBoidNeighbourhood(this);

	float maxDistance = 3;
	// apply forces
	targetVelocity += Separation(closestBoids) * parameters->separationWeight;
	targetVelocity += Cohesion(closestBoids) * parameters->cohesionWeight;
	targetVelocity += Alignment(closestBoids) * parameters->alignmentWeight;

	targetVelocity.Normalize();

	// if velocity is small add wandering behavior
	if (targetVelocity.Size() < 1) {
		targetVelocity += Wander(100, 200, 10);
		targetVelocity.Normalize();
	}

	FVector newForce = targetVelocity - currentVelocity;
	currentVelocity += newForce * DeltaTime;

	// update position
	FVector location = GetActorLocation();
	location += currentVelocity * parameters->speed * DeltaTime;

	// rotate root component to align with direction
	FVector coneDirection = currentVelocity.GetSafeNormal();
	root->SetWorldRotation(coneDirection.Rotation());

	SetActorLocation(location);
}

void ABoid::SetConeMaterial(UMaterialInterface* material)
{
	mesh->SetMaterial(0, material);
}

// apply containment force to keep boids within sphere
// TODO fix whatever is making boids stick to the boundary
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