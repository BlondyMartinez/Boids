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

	// SPAWN SETTINGS

	UPROPERTY (Config, EditAnywhere, BlueprintReadOnly, Category = "Spawn Settings")
	int spawnCount = 30;
	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = "Spawn Settings")
	int spawnRadius = 500;

	// BOID SETTINGS

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Boid Settings")
	int speed = 200;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Boid Settings")
	int maxFleeDistance = 9000;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Boid Settings")
	int chaserMultiplier = 2;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Boid Settings")
	int catchRange = 100;

	float timeoutTime = 5.f;

	USceneComponent* transform;

	TArray<class ABoid*> boids;
	class ABoid* lastTagged;
	class ABoid* tagged;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	 
	FVector ClosestBoidPosition(class ABoid* thisBoid);
};
