// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidManager.h"
#include "Boid.h"
#include "BoidManagerParameters.h"

// Sets default values
ABoidManager::ABoidManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// add transform component as root
	transform = CreateDefaultSubobject<USceneComponent>("Root Scene Component");
	SetRootComponent(transform);
}

// Called when the game starts or when spawned
void ABoidManager::BeginPlay()
{
	Super::BeginPlay();

	// spawn containment sphere
	containmentSphere = SpawnContainmentSphere();

	// spawn
	for (int i = 0; i < parameters->spawnCount; i++) {
		// generate random spawn position within specified radius
		FVector spawnPos = (FMath::VRand() * FMath::RandRange(0, parameters->spawnRadius)) + GetActorLocation();
		FRotator spawnRot = GetActorRotation();

		// generate random color index
		int colorIndex = FMath::RandRange(0, 3);

		// spawn boid with specified parameters
		ABoid* newBoid = GetWorld()->SpawnActor<ABoid>(spawnPos, spawnRot);
		newBoid->speed = parameters->speed;
		newBoid->color = colorIndex;
		newBoid->manager = this;
		newBoid->SetConeMaterial(materials[colorIndex]);
		boids.Add(newBoid);
	}
}

// spawn containment sphere
AActor* ABoidManager::SpawnContainmentSphere()
{
	if (containmentSphereClass) {
		// spawn at boidmanager location
		AActor* aContainmentSphere = GetWorld()->SpawnActor<AActor>(containmentSphereClass, GetActorLocation(), GetActorRotation());
		// sohere properties
		sphereCentre = aContainmentSphere->GetActorLocation();
		sphereRadius = 2400;
		return aContainmentSphere;
	}

	return nullptr;
}

// get neighbourhood of a boid
TArray<class ABoid*> ABoidManager::GetBoidNeighbourhood(ABoid* thisBoid)
{
	TArray<class ABoid*> neighbourhood;

	// iterate through all boids to find neighbours within specified radius
	for (ABoid* boid : boids) {
		if (boid == thisBoid || !boid) continue;

		float distance = (boid->GetActorLocation() - thisBoid->GetActorLocation()).Size();
		if (distance < parameters->neighbourhoodRadius) neighbourhood.Add(boid);
	}

	return neighbourhood;
}

// Called every frame
void ABoidManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (ABoid* boid : boids) {
		boid->UpdateBoid(DeltaTime);
	}

}

// getters for parameters from data asset
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

float ABoidManager::colorBias()
{
	return parameters->colorBias;
}