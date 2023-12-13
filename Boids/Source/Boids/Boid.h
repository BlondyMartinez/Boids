// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boid.generated.h"

UCLASS()
class BOIDS_API ABoid : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABoid();

	class ABoidManager* manager = nullptr;
	class AGridActor* grid = nullptr;
	class UBoidManagerParameters* parameters = nullptr;
	class UNiagaraComponent* ribbon = nullptr;
	class UMaterialInstanceDynamic* mat = nullptr;

	int color = 0;
	float speed = 0;

	bool inDanger = false;

	FVector currentVelocity = FVector::ZeroVector;

	UPROPERTY(VisibleAnywhere, Category = "Grid")
	TArray<ABoid*> nearbyBoids;
	UPROPERTY(VisibleAnywhere, Category = "Grid")
	TArray<class APredator*> nearbyPredators;

protected:

	UStaticMeshComponent* mesh;
	USceneComponent* root;

	float mass = 0;
	float massInverse = 0;

	// BEHAVIOUR STUFF
	
	FVector Seek(const FVector& pos);
	FVector Flee(const FVector& pos);

	FVector Separation(const TArray<ABoid*>& neighbours);
	FVector Cohesion(const TArray<ABoid*>& neighbours);
	FVector Alignment(const TArray<ABoid*>& neighbours);

	FVector Wander(float distance, float jitter);
	FVector wanderDestination;

	FVector Repulsion(const TArray<ABoid*>& neighbours);
	FVector ObstacleAvoidance(const TArray<AActor*>& obstacles);
	FVector Evade(const TArray<class APredator*>& predators);

	FVector ApplyContainment();

	void GetNearbyEntities();
	void AddPredator(APredator* predator);

	void Saturate(float saturationMultiplier);

public:

	void KillBoid();

	// called from boidManager

	void UpdateBoid(float DeltaTime);

	void SetConeMaterial(UMaterialInterface* material);
	void SetConeScale(float aMass);
	void AssignRibbonToComponent(class UNiagaraSystem* ribbonSystem);
};