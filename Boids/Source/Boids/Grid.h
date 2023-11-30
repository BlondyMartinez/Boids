// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class BOIDS_API Grid
{
public:
	Grid(UWorld* world, float gridSize, float cellSize, FVector sphereCentre, float sphereRadius)
	{
		this->world = world;

		this->gridSize = gridSize;
		this->cellSize = cellSize;
		halfCellSize = cellSize / 2;
		cellSizeInverse = 1 / cellSize;
		cellsPerSide = FMath::CeilToInt(gridSize / cellSize);

		this->sphereCentre = sphereCentre;
		this->sphereRadius = sphereRadius;
	}

	~Grid() {}

	void UpdateGrid(const TArray<class ABoid*>& boids);

	// debug grid stuff
	// NOTAS caro
	void DrawDebugGrid();

	TArray <class ABoid*> GetNeighbours(class ABoid* boid);

private:
	int GetCellIndex(const FVector& pos);

	TMap<int, TArray<class ABoid*>> grid; // NOTAS map = vector asociativo

	UWorld* world;

	float gridSize; // containmentsphere diameter at least
	float cellSize; // neighbourhoodradius at least
	float halfCellSize;
	float cellSizeInverse;
	FVector cellCentre;
	int cellsPerSide;

	FVector sphereCentre;
	float sphereRadius;


	void DrawGridCell();

	FVector GetCellCentre(int cellIndex);
};
