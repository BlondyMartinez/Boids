// Fill out your copyright notice in the Description page of Project Settings.


#include "Boid.h"
#include "BoidManager.h"
#include "DrawDebugHelpers.h"

// Sets default values
ABoid::ABoid()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	UStaticMesh* sphereMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'")).Object;
	mesh->SetStaticMesh(sphereMesh);
	SetRootComponent(mesh);

}

// Called when the game starts or when spawned
void ABoid::BeginPlay()
{
	Super::BeginPlay();

}

FVector ABoid::Seek(FVector pos)
{
	FVector newVelocity = pos - GetActorLocation();
	newVelocity.Normalize();
	return newVelocity;
}

FVector ABoid::Flee(FVector pos)
{
	FVector newVelocity = GetActorLocation() - pos;
	newVelocity.Normalize();
	return newVelocity;
}

FVector ABoid::Separation(TArray<ABoid*> neighbours)
{
	if (neighbours.Num() == 0) return FVector::ZeroVector;

	FVector avgFlee;
	//float inverse = 1 / neighbours.Num();

	for (ABoid* boid : neighbours) {
		avgFlee += Flee(boid->GetActorLocation());
	}

	avgFlee.Normalize();

	return avgFlee;
}

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

	TArray<ABoid*> closestBoids = manager->GetBoidNeighbourhood(this);

	targetVelocity += Separation(closestBoids) * manager->separationWeight();
	targetVelocity += Cohesion(closestBoids) * manager->cohesionWeight();
	targetVelocity += Alignment(closestBoids) * manager->alignmentWeight();

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%f"), manager->separationWeight()));

	targetVelocity.Normalize();

	if (targetVelocity.Size() < 1) {
		targetVelocity += Wander(100, 200, 50);
		targetVelocity.Normalize();
	}

	DrawDebugLine(GetWorld(), GetActorLocation(), targetVelocity, FColor::Green, false, 0, 0, 5);

	FVector newForce = targetVelocity - currentVelocity;
	currentVelocity += newForce * DeltaTime;

	FVector location = GetActorLocation();
	location += currentVelocity * speed * DeltaTime;

	SetActorLocation(location);
}


// Called every frame
void ABoid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}