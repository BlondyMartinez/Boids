// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidManager.h"
#include "Boid.h"
#include "BoidManagerParameters.h"

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

	containmentSphere = SpawnContainmentSphere();

	// SPAWN
	for (int i = 0; i < parameters->spawnCount; i++) {
		FVector spawnPos = (FMath::VRand() * FMath::RandRange(0, parameters->spawnRadius)) + GetActorLocation();
		FRotator spawnRot = GetActorRotation();

		ABoid* newBoid = GetWorld()->SpawnActor<ABoid>(spawnPos, spawnRot);
		newBoid->speed = parameters->speed;
		newBoid->manager = this;
		boids.Add(newBoid);
	}
}

AActor* ABoidManager::SpawnContainmentSphere()
{
	if (containmentSphereClass) {
		AActor* aContainmentSphere = GetWorld()->SpawnActor<AActor>(containmentSphereClass, GetActorLocation(), GetActorRotation());
		sphereCentre = aContainmentSphere->GetActorLocation();
		sphereRadius = 3500;
		return aContainmentSphere;
	}

	return nullptr;
}

// Called every frame
void ABoidManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (ABoid* boid : boids) {
		boid->UpdateBoid(DeltaTime);
	}

}

float ABoidManager::separationWeight()
{
	return parameters->separationWeight;
}

float ABoidManager::cohesionWeight()
{
	return parameters->cohesionWeight;
}

float ABoidManager::alignmentWeight()
{
	return parameters->alignmentWeight;
}

float ABoidManager::containmentForce()
{
	return parameters->containmentForce;
}

TArray<class ABoid*> ABoidManager::GetBoidNeighbourhood(ABoid* thisBoid)
{
	TArray<class ABoid*> neighbourhood;

	for (ABoid* boid : boids) {
		if (boid == thisBoid || !boid) continue;

		float distance = (boid->GetActorLocation() - thisBoid->GetActorLocation()).Size();
		if (distance < parameters->neighbourhoodRadius) neighbourhood.Add(boid);
	}

	return neighbourhood;
}