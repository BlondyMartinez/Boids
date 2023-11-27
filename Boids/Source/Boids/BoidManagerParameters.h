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
	int spawnCount = 30;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Settings")
	int spawnRadius = 500;

	// BOID SETTINGS

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boid Settings")
	int speed = 200;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boid Settings")
	int neighbourhoodRadius = 900;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boid Settings")
	float separationWeight = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boid Settings")
	float cohesionWeight = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boid Settings")
	float alignmentWeight = 1;
	//if too big boids get shot
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boid Settings")
	float containmentForce = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boid Settings")
	float colorBias = 1;
};
