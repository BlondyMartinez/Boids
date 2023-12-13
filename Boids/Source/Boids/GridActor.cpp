// Fill out your copyright notice in the Description page of Project Settings.

#include "GridActor.h"
#include "Boid.h"
#include "Predator.h"


void AGridActor::InitializeGrid(FVector centre, float radius, int res)
{
	sphereCentre = centre;
	sphereRadius = radius;
	gridRes = res;

	GenerateGrid();
}

void AGridActor::GenerateGrid()
{
	// cell size is sphere diameter divided by grid resolution
	float cellSize = (2 * sphereRadius) / gridRes;

	// get corner of the cell
	FVector startPoint = sphereCentre - FVector(sphereRadius);

	// 3 loops to cover entire volume of the sphere
	for (int x = 0; x < gridRes; x++) {
		for (int y = 0; y < gridRes; y++) {
			for (int z = 0; z < gridRes; z++) {
				// get cell centre by calculating the distance to move from startPoint to the corner of the current cell + half cell size
				FVector cellCentre = startPoint + FVector(z * cellSize, y * cellSize, x * cellSize) + FVector(cellSize * .5f);
				gridCells.Add(GridCell{ cellCentre, cellSize });
			}
		}
	}
}

// called from boidmanager
void AGridActor::UpdateGrid(const TArray<class ABoid*>& boids, const TArray<class APredator*>& predators)
{
	// clear non-static content of each cell
	for (GridCell cell : gridCells) {
		cell.boids.Empty();
		cell.predators.Empty();
	}

	for (ABoid* boid : boids) {
		int cellIndex = GetCellIndex(boid->GetActorLocation());
		// if index is valid, boid is valid and it isnt in the array already and is not marked to be destroyed add boid to cell boids array
		if (cellIndex >= 0 && cellIndex < gridCells.Num() && !gridCells[cellIndex].boids.Contains(boid) && IsValid(boid)) gridCells[cellIndex].boids.Add(boid);
	}

	for (APredator* predator : predators) {
		int cellIndex = GetCellIndex(predator->GetActorLocation());
		if (cellIndex >= 0 && cellIndex < gridCells.Num() && !gridCells[cellIndex].predators.Contains(predator) && IsValid(predator)) gridCells[cellIndex].predators.Add(predator);
	}
}

int AGridActor::GetCellIndex(const FVector& pos)
{
	// world pos to pos within grid
	FVector relativePos = ((pos - sphereCentre) / (sphereRadius * 2)) + FVector(.5f);
	relativePos *= gridRes;

	// coordinates to indices
	int x = FMath::Clamp(FMath::FloorToInt(relativePos.X), 0, gridRes - 1);
	int y = FMath::Clamp(FMath::FloorToInt(relativePos.Y), 0, gridRes - 1);
	int z = FMath::Clamp(FMath::FloorToInt(relativePos.Z), 0, gridRes - 1);

	// 3d to 1d index
	return x + (y * gridRes) + (z * gridRes * gridRes);
}

TArray<int> AGridActor::GetAdjacentCellIndices(int currentCellIndex)
{
	TArray<int> adjacentIndices;
	// calculate number of cells along one axis
	int gridWidth = FMath::RoundToInt(FMath::Pow(gridCells.Num(), 1.f / 3.f));

	// convert 1d index of current cell to 3d coordinates
	int x = currentCellIndex % gridWidth;
	int y = (currentCellIndex / gridWidth) % gridWidth;
	int z = (currentCellIndex / (gridWidth * gridWidth));

	for (int ix = -1; ix <= 1; ix++) {
		for (int iy = -1; iy <= 1; iy++) {
			for (int iz = -1; iz <= 1; iz++) {
				if (ix == 0 && iy == 0 && iz == 0) continue;
				if (ix < 0 || ix >= gridWidth) continue;
				if (iy < 0 || iy >= gridWidth) continue;
				if (iz < 0 || iz >= gridWidth) continue;

				int newX = x + ix;
				int newY = y + iy;
				int newZ = z + iz;
				int newIndex = newX + newY * gridWidth + newZ * gridWidth * gridWidth;
				adjacentIndices.Add(newIndex);
			}
		}
	}

	return adjacentIndices;
}

TArray<class ABoid*> AGridActor::GetBoidsInCell(int cellIndex)
{
	// if valid cell index return boids in cell
	if (cellIndex >= 0 && cellIndex < gridCells.Num()) return gridCells[cellIndex].boids;

	return TArray<class ABoid*>();
}

TArray<class APredator*> AGridActor::GetPredatorsInCell(int cellIndex)
{
	// if valid cell index return predators in cell
	if (cellIndex >= 0 && cellIndex < gridCells.Num()) return gridCells[cellIndex].predators;

	return TArray<class APredator*>();
}
