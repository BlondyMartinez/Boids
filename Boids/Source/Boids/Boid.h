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

	FVector currentVelocity = FVector::ZeroVector;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//first tutorial functions
	FVector Seek(FVector pos);
	FVector Flee(FVector pos);

	//second tutorial functions
	FVector Separation(TArray<ABoid*> neighbours);
	FVector Cohesion(TArray<ABoid*> neighbours);
	FVector Alignment(TArray<ABoid*> neighbours);

	FVector Wander(float radius, float distance, float jitter);
	FVector wanderDestination;

	UStaticMeshComponent* mesh;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void UpdateBoid(float DeltaTime);
};