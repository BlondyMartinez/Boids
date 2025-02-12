// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridActor.generated.h"

UCLASS()
class BOIDS_API AGridActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridActor() {}

	void InitializeGrid(FVector centre, float radius, int res);
	void GenerateGrid();

	void UpdateGrid(const TArray<class ABoid*>& boids, const TArray<class APredator*>& predators);

	int GetCellIndex(const FVector& pos);
	TArray<int>GetAdjacentCellIndices(int CurrentCellIndex);

	TArray<class ABoid*> GetBoidsInCell(int cellIndex);
	TArray<class APredator*> GetPredatorsInCell(int cellIndex);

protected:
	struct GridCell{
	FVector centre;  
	float size;      
	TArray<class ABoid*> boids;
	TArray<class APredator*> predators;
	};

	TArray<GridCell> gridCells;

	float sphereRadius = 0;
	FVector sphereCentre = FVector::ZeroVector;
	int gridRes = 0; // divisions along each axis
};
