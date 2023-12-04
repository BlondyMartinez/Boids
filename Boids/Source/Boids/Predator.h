// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Predator.generated.h"

UCLASS()
class BOIDS_API APredator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APredator();

	class ABoidManager* manager;
	class UBoidManagerParameters* parameters;

	class ABoid* prey;

	FVector currentVelocity = FVector::ZeroVector;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float massInverse;

	UStaticMeshComponent* mesh;
	USceneComponent* root;

	FVector Pursue(class ABoid* boid);
	FVector ApplyContainment();

public:	
	void UpdatePredator(float DeltaTime);
	void SetPredatorMaterial(UMaterialInterface* mat);
};
