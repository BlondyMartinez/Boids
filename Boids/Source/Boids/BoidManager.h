// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoidManager.generated.h"

UCLASS()
class BOIDS_API ABoidManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABoidManager();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	class UBoidManagerParameters* parameters;

	// SPAWN SETTINGS

	int spawnCount = 30;
	int spawnRadius = 500;

	// BOID SETTINGS

	int speed = 200;
	int neighbourhoodRadius = 600;

	float separationWeight();
	float cohesionWeight();
	float alignmentWeight();

	USceneComponent* transform;

	TArray<class ABoid*> boids;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	TArray<class ABoid*>GetBoidNeighbourhood(class ABoid* thisBoid);
};