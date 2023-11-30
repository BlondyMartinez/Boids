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

	USceneComponent* transform;

	TArray<class ABoid*> boids;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	class UBoidManagerParameters* parameters;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	TSubclassOf<class AActor> containmentSphereClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	TArray<UMaterialInterface*> materials;
	/*UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	class Grid* grid;*/

	// containment sphere parameters
	AActor* containmentSphere;
	FVector sphereCentre;
	float sphereRadius;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	AActor* SpawnContainmentSphere();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	TArray<class ABoid*>GetBoidNeighbourhood(class ABoid* thisBoid);
};