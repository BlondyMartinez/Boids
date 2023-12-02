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

	//behavior currentBehavior = behavior::flocking;

	int color;
	float speed;

protected:
	FVector currentVelocity = FVector::ZeroVector;

	UStaticMeshComponent* mesh;
	USceneComponent* root;

	bool towardsCentre = true;

	float mass;
	float massInverse;

	// BEHAVIOUR STUFF
	
	// first tutorial
	FVector Seek(FVector pos);
	FVector Flee(FVector pos);

	// second tutorial
	// TODO change functions to have all of their logic happening in the same loop 
	// instead of a loop for each
	FVector Separation(TArray<ABoid*> neighbours);
	FVector Cohesion(TArray<ABoid*> neighbours);
	FVector Alignment(TArray<ABoid*> neighbours);

	FVector Wander(float radius, float distance, float jitter);
	FVector wanderDestination;

	FVector ApplyContainment();
	FVector Repulsion(TArray<ABoid*> neighbours);
	//TODO
	FVector GroupAvoidance(TArray<ABoid*> neighbours);

	void SpiralMovement(float DeltaTime);
	void Flocking(float DeltaTime);

public:
	void UpdateBoid(float DeltaTime);
	void SetConeMaterial(UMaterialInterface* material);
	void SetConeScale(float aMass);
};

// GIVES EEVERAL ERRORS WHEN COMPILING IN UNREAL
//enum class behavior {
//	flocking, // standard movement
//	spiral,   // spiral movement
//};