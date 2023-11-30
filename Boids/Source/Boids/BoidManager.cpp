// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidManager.h"
#include "Boid.h"
#include "BoidManagerParameters.h"
#include "Grid.h"

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

	// add grid
	//grid = new Grid(GetWorld(), sphereRadius * 2, parameters->neighbourhoodRadius, sphereCentre, sphereRadius);

	// spawn
	for (int i = 0; i < parameters->spawnCount; i++) {
		// position
		FVector spawnPos = (FMath::VRand() * FMath::RandRange(0, parameters->spawnRadius)) + GetActorLocation();
		FRotator spawnRot = GetActorRotation();

		// color
		int colorIndex = FMath::RandRange(0, 3);

		// spawn boid with specified parameters
		ABoid* newBoid = GetWorld()->SpawnActor<ABoid>(spawnPos, spawnRot);
		newBoid->parameters = parameters;
		newBoid->color = colorIndex;
		newBoid->manager = this;
		newBoid->SetConeMaterial(materials[colorIndex]);
		boids.Add(newBoid);
	}
}

AActor* ABoidManager::SpawnContainmentSphere()
{
	if (containmentSphereClass) {
		AActor* aContainmentSphere = GetWorld()->SpawnActor<AActor>(containmentSphereClass, GetActorLocation(), GetActorRotation());
		
		// sphere properties
		sphereCentre = aContainmentSphere->GetActorLocation();
		sphereRadius = 2300; // aprox sphere scale * 100 / 2
		return aContainmentSphere;
	}

	return nullptr;
}

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
	//grid->UpdateGrid(boids);
	for (ABoid* boid : boids) {
		boid->UpdateBoid(DeltaTime);
	}
	//grid->DrawDebugGrid();
}