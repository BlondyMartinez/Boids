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

	float speed;
	int color;

protected:
	FVector currentVelocity = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* mesh;
	USceneComponent* root;

	// BEHAVIOUR STUFF
	
	//first tutorial functions
	FVector Seek(FVector pos);
	FVector Flee(FVector pos);

	//second tutorial functions
	FVector Separation(TArray<ABoid*> neighbours);
	FVector Cohesion(TArray<ABoid*> neighbours);
	FVector Alignment(TArray<ABoid*> neighbours);

	FVector Wander(float radius, float distance, float jitter);
	FVector wanderDestination;

	FVector SeparationByColor(TArray<ABoid*> neighbours);

	void ApplyContainment();

public:
	void UpdateBoid(float DeltaTime);
	void SetConeMaterial(UMaterialInterface* material);
};