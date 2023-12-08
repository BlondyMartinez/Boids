// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidManager.h"
#include "Boid.h"
#include "Predator.h"
#include "BoidManagerParameters.h"
#include "GridActor.h"
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

	// containment sphere
	containmentSphere = SpawnContainmentSphere();
	HideContainmentSphere(true);

	// grid
	SpawnGridActor();

	// spawn
	SpawnBoids(parameters->spawnCount);
}

// Called every frame
void ABoidManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (ABoid* boid : boids) {
		boid->UpdateBoid(DeltaTime);
	}

	for (APredator* predator : predators) {
		predator->UpdatePredator(DeltaTime);
	}

	grid->UpdateGrid(boids, predators);
	UE_LOG(LogTemp, Warning, TEXT("boids: %d"), boids.Num());
}

// spawn containment sphere 
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

void ABoidManager::SpawnGridActor()
{
	grid = GetWorld()->SpawnActor<AGridActor>(GetActorLocation(), GetActorRotation());
	grid->InitializeGrid(sphereCentre, sphereRadius, 20);
}

// get boids nearby
TArray<class ABoid*> ABoidManager::GetBoidNeighbourhood(const class ABoid* thisBoid)
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

// get nearby obstacles
TArray<AActor*> ABoidManager::GetNearbyObstacles(const class ABoid* thisBoid)
{
	TArray <AActor*> nearbyObstacles;

	// iterate through all obstacles to find those within neighbourhoodradius plus each obstacle radius
	for (AActor* anObstacle : obstacles) {
		float obstacleRadius = anObstacle->GetActorScale3D().X * 100 * .5f;  
		float distance = (anObstacle->GetActorLocation() - thisBoid->GetActorLocation()).Size() - obstacleRadius;

		if (distance < parameters->neighbourhoodRadius) nearbyObstacles.Add(anObstacle);
	}

	return nearbyObstacles;
}

TArray<class APredator*> ABoidManager::GetNearbyPredators(const ABoid* thisBoid)
{
	TArray<class APredator*> nearbyPredators;

	// find predators within neighbourhoodradius and add them to nearbyPredators
	for (APredator* predator : predators) {
		float distance = (predator->GetActorLocation() - thisBoid->GetActorLocation()).Size();
		if (distance < parameters->neighbourhoodRadius) nearbyPredators.Add(predator);
	}

	return nearbyPredators;
}

ABoid* ABoidManager::GetClosestBoid(const APredator* predator)
{
	ABoid* boid = nullptr;
	float minDistance = FLT_MAX;

	for (ABoid* aBoid : boids) {
		float distance = FVector::Dist(predator->GetActorLocation(), aBoid->GetActorLocation());
		if (distance < minDistance) {
			minDistance = distance;
			boid = aBoid;
		}
	}

	return boid;
}

// blueprint callable funcitons

// spawn boids
void ABoidManager::SpawnBoids(int amount)
{
	for (int i = 0; i < amount; i++) {
		// position
		FVector spawnPos = (FMath::VRand() * FMath::RandRange(0, parameters->spawnRadius)) + GetActorLocation();
		FRotator spawnRot = GetActorRotation();

		// color
		int colorIndex = FMath::RandRange(0, 3);
		float mass = FMath::RandRange(.5f, 1.f);

		// spawn boid with specified parameters
		ABoid* newBoid = GetWorld()->SpawnActor<ABoid>(spawnPos, spawnRot);

		newBoid->parameters = parameters;
		newBoid->grid = grid;
		newBoid->manager = this;

		newBoid->speed = parameters->speed * .65f / mass; // greater speed the lighter the boid is
		newBoid->color = colorIndex;

		newBoid->SetConeMaterial(materials[colorIndex]);
		newBoid->AssignRibbonToComponent(ribbons[colorIndex]);
		newBoid->SetConeScale(mass);

		if (!parameters->visibleRibbon) DeactivateRibbon();

		boids.Add(newBoid);
	}
}

// remove amount of boids
void ABoidManager::RemoveBoids(int amount)
{
	int count = boids.Num();

	// destroy and remove last item of boids if there are more boids than the given amount
	if (count >= amount) {
		for (int i = (count - 1); i >= (count - amount); i--) {
			boids[i]->Destroy();
			boids.Pop();
		}
	}
	// else destroy all and empty boids array
	else {
		for (ABoid* boid : boids) {
			boid->Destroy();
		}
		boids.Empty();
	}

	grid->UpdateGrid(boids, predators);
}

// return amount of boids
int ABoidManager::BoidsCount()
{
	return boids.Num();
}

// show or hide containment sphere
void ABoidManager::HideContainmentSphere(bool hide)
{
	containmentSphere->SetActorHiddenInGame(hide);
}

// activate ribbon particle system
void ABoidManager::ActivateRibbon()
{
	for (ABoid* boid : boids) {
		boid->ribbon->ActivateSystem();
	}
}

// deactivate ribbon particle system
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
	grid->AddObstacleToCell(anObstacle);
}

// destroy last added obstacle and remove it from obstacles
void ABoidManager::RemoveLastObstacle()
{
	if (obstacles.Num() > 0) {
		obstacles[obstacles.Num() - 1]->Destroy();
		obstacles.Pop();
	}
}

// destroy all obstacles and empty obstacles array
void ABoidManager::ClearObstacles()
{
	if (obstacles.Num() > 0) {
		for (AActor* anObstacle : obstacles) {
			anObstacle->Destroy();
		}

		obstacles.Empty();
	}
}

// spawn predator at random location and add it to predators array
void ABoidManager::SpawnPredator()
{
	// position
	FVector spawnPos = (FMath::VRand() * FMath::RandRange(0, parameters->spawnRadius)) + GetActorLocation();
	FRotator spawnRot = GetActorRotation();

	// spawn predator with specified parameters
	APredator* newPredator = GetWorld()->SpawnActor<APredator>(spawnPos, spawnRot);
	newPredator->parameters = parameters;
	newPredator->manager = this;
	newPredator->SetPredatorMaterial(materials[4]);

	predators.Add(newPredator);
}

// destroy last predator element of the array
void ABoidManager::RemoveLastPredator()
{
	if (predators.Num() > 0) {
		predators[predators.Num() - 1]->Destroy();
		predators.Pop();
	}
}

// destroy all predators and empty predators array
void ABoidManager::ClearPredators()
{
	if (predators.Num() > 0) {
		for (APredator* predator : predators) {
			predator->Destroy();
		}

		predators.Empty();
	}
}