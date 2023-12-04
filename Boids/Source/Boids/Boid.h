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

	class ABoidManager* manager;
	class UBoidManagerParameters* parameters;
	class UNiagaraComponent* ribbon;

	//behavior currentBehavior = behavior::flocking;

	int color;
	float speed;

	FVector currentVelocity = FVector::ZeroVector;

protected:

	UStaticMeshComponent* mesh;
	USceneComponent* root;

	bool towardsCentre = true;

	float mass;
	float massInverse;

	// BEHAVIOUR STUFF
	
	FVector Seek(const FVector& pos);
	FVector Flee(const FVector& pos);

	FVector Separation(const TArray<ABoid*>& neighbours);
	FVector Cohesion(const TArray<ABoid*>& neighbours);
	FVector Alignment(const TArray<ABoid*>& neighbours);

	FVector Wander(float radius, float distance, float jitter);
	FVector wanderDestination;

	FVector Repulsion(const TArray<ABoid*>& neighbours);
	FVector ObstacleAvoidance(const TArray<AActor*>& obstacles);

	FVector Evade(const TArray<class APredator*>& predators);

	FVector ApplyContainment();

	void SpiralMovement(float DeltaTime);
	void Flocking(float DeltaTime);

public:
	void KillBoid();

	// called from boidManager

	void UpdateBoid(float DeltaTime);
	void SetConeMaterial(UMaterialInterface* material);
	void SetConeScale(float aMass);
	void AssignRibbonToComponent(class UNiagaraSystem* ribbonSystem);
};

// GIVES EEVERAL ERRORS WHEN COMPILING IN UNREAL
//enum class behavior {
//	flocking, // standard movement
//	spiral,   // spiral movement
//};