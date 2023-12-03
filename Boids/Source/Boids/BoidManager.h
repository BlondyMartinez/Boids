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
	TArray<AActor*> obstacles;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	class UBoidManagerParameters* parameters;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	TSubclassOf<class AActor> containmentSphereClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	TSubclassOf<class AActor> obstacle;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	TArray<UMaterialInterface*> materials;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	TArray<class UNiagaraSystem*> ribbons;
	/*UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	class Grid* grid;*/

	UFUNCTION(BlueprintCallable, Category = "Boid Behavior")
	void HideContainmentSphere(bool hide);
	UFUNCTION(BlueprintCallable, Category = "Boid Behavior")
	void ActivateRibbon();
	UFUNCTION(BlueprintCallable, Category = "Boid Behavior")
	void DeactivateRibbon();

	UFUNCTION(BlueprintCallable, Category = "Simulation Settings")
	void AddObstacle();
	UFUNCTION(BlueprintCallable, Category = "Simulation Settings")
	void RemoveLastObstacle();
	UFUNCTION(BlueprintCallable, Category = "Simulation Settings")
	void ClearObstacles();

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
	TArray<AActor*>GetNearbyObstacles(class ABoid* thisBoid);
};