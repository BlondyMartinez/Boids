// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidManager.h"
#include "Boid.h"
#include "BoidManagerParameters.h"
#include "Grid.h"
#include "NiagaraComponent.h"

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
	HideContainmentSphere(true);

	// add grid
	//grid = new Grid(GetWorld(), sphereRadius * 2, parameters->neighbourhoodRadius, sphereCentre, sphereRadius);

	// spawn
	for (int i = 0; i < parameters->spawnCount; i++) {
		// position
		FVector spawnPos = (FMath::VRand() * FMath::RandRange(0, parameters->spawnRadius)) + GetActorLocation();
		FRotator spawnRot = GetActorRotation();

		// color
		int colorIndex = FMath::RandRange(0, 3);
		float mass = FMath::RandRange(.5f, 1.f);

		// spawn boid with specified parameters
		ABoid* newBoid = GetWorld()->SpawnActor<ABoid>(spawnPos, spawnRot);
		newBoid->parameters = parameters;
		newBoid->speed = parameters->speed * .65f / mass; // greater speed the lighter the boid is
		newBoid->color = colorIndex;
		newBoid->manager = this;
		newBoid->SetConeMaterial(materials[colorIndex]);
		newBoid->AssignRibbonToComponent(ribbons[colorIndex]);
		newBoid->SetConeScale(mass);

		boids.Add(newBoid);
	}
}

AActor* ABoidManager::SpawnContainmentSphere()
{
	if (containmentSphereClass) {
		AActor* aContainmentSphere = GetWorld()->SpawnActor<AActor>(containmentSphereClass, GetActorLocation(), GetActorRotation());
		UStaticMeshComponent* containmentMesh= aContainmentSphere->FindComponentByClass<UStaticMeshComponent>();

		// sphere properties
		sphereCentre = aContainmentSphere->GetActorLocation();
		sphereRadius = (containmentMesh->GetComponentScale().X * 100 * .5f) - 200; 
		
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

TArray<AActor*> ABoidManager::GetNearbyObstacles(ABoid* thisBoid)
{
	TArray <AActor*> nearbyObstacles;

	for (AActor* anObstacle : obstacles) {
		float obstacleRadius = anObstacle->GetActorScale3D().X * 100 * .5f;
		float distance = (anObstacle->GetActorLocation() - thisBoid->GetActorLocation()).Size() - obstacleRadius;

		if (distance < parameters->neighbourhoodRadius) nearbyObstacles.Add(anObstacle);
	}

	return nearbyObstacles;
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

void ABoidManager::HideContainmentSphere(bool hide)
{
	containmentSphere->SetActorHiddenInGame(hide);
}

void ABoidManager::ActivateRibbon()
{
	for (ABoid* boid : boids) {
		boid->ribbon->ActivateSystem();
	}
}

void ABoidManager::DeactivateRibbon()
{
	for (ABoid* boid : boids) {
		boid->ribbon->Deactivate();
	}
}

// spawn obstacle at random location with random scale and adds it to obstacles array
void ABoidManager::AddObstacle()
{
	FVector spawnPos = (FMath::VRand() * FMath::RandRange(0, parameters->spawnRadius)) + GetActorLocation();

	AActor* anObstacle = GetWorld()->SpawnActor<AActor>(obstacle, spawnPos, GetActorRotation());
	
	float scale = FMath::RandRange(5, 15);
	anObstacle->SetActorScale3D(FVector(scale));

	obstacles.Add(anObstacle);
}
