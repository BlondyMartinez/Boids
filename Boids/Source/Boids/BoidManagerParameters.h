// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BoidManagerParameters.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class BOIDS_API UBoidManagerParameters : public UDataAsset
{
	GENERATED_BODY()
	
public:

	// SPAWN SETTINGS

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Settings")
	int spawnCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Settings")
	int spawnRadius;

	// BOID SETTINGS

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boid Settings")
	int speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boid Settings")
	int neighbourhoodRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boid Settings")
	float separationWeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boid Settings")
	float cohesionWeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boid Settings")
	float alignmentWeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boid Settings")
	float containmentForce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boid Settings")
	float repulsionForce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boid Settings")
	bool colorBias;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boid Settings")
	int behaviorStateIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boid Settings")
	float obstacleAvoidanceForce;
};
