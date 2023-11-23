// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidManager.h"
#include "Boid.h"

// Sets default values
ABoidManager::ABoidManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// adds transform component
	transform = CreateDefaultSubobject<USceneComponent>("Root Scene Component");
	SetRootComponent(transform);

}

// Called when the game starts or when spawned
void ABoidManager::BeginPlay()
{
	Super::BeginPlay();
	
	// SPAWN
	for (int i = 0; i < spawnCount; i++) {
		FVector spawnPos = (FMath::VRand() * spawnRadius) + GetActorLocation();
		FRotator spawnRot = GetActorRotation();

		ABoid* newBoid = GetWorld()->SpawnActor<ABoid>(spawnPos, spawnRot);
		newBoid->speed = speed;
		newBoid->manager = this;
		boids.Add(newBoid);
	}

	tagged = boids[0];
}

// Called every frame
void ABoidManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	for (ABoid* boid : boids) {
		boid->UpdateBoid(DeltaTime);
	}

}

FVector ABoidManager::ClosestBoidPosition(ABoid* thisBoid)
{
	float closestDistance = maxFleeDistance;
	FVector returnVal = GetActorLocation();

	for (ABoid* boid : boids) {
		if (boid == thisBoid || !boid || boid == lastTagged) continue;

		float distance = (boid->GetActorLocation() - thisBoid->GetActorLocation()).Size();
		if (distance < closestDistance) {
			closestDistance = distance;
			returnVal = boid->GetActorLocation();
		}

		if (thisBoid == tagged) {
			if (closestDistance < catchRange) {
				lastTagged = tagged;
				tagged = boid;
				tagged->waitCounter = timeoutTime;
			}
		}
	}

	return returnVal;
}

