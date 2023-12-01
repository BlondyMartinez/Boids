// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid.h"
#include "Boid.h"

// called from boidmanager
void Grid::UpdateGrid(const TArray<class ABoid*>& boids)
{
	grid.Empty();

	// calculate cell index of each boid and add it to the corresponding cell
	for (ABoid* boid : boids) {
		int index = GetCellIndex(boid->GetActorLocation());
		if (!grid.Contains(index)) {
			grid.Add(index, TArray <ABoid*>());
		}
		
		grid[index].Add(boid);
	}
}

void Grid::DrawDebugGrid()
{
	TSet<int> cellIndices; // NOTAS tset evita duplicados y es más eficiente pero no hay acceso con índice

	for (const auto& element : grid) { // NOTAS auto concluye automáticamente el tipo de variable
		cellIndices.Add(element.Key);
	}

	for (int cellIndex : cellIndices) {
		cellCentre = GetCellCentre(cellIndex);
		DrawGridCell();
	}
}

void Grid::DrawGridCell()
{
	FVector half = FVector(halfCellSize);
	DrawDebugBox(world, cellCentre, half, FColor::Green, false, 0);
}

// TODO celdas adyacentes
TArray<class ABoid*> Grid::GetNeighbours(ABoid* boid)
{
	TArray <ABoid*> neighbours;

	int index = GetCellIndex(boid->GetActorLocation());
	if (grid.Contains(index)) neighbours.Append(grid[index]);

	return neighbours;
}

int Grid::GetCellIndex(const FVector& pos)
{
	FVector relativePos = pos - sphereCentre;

	// pos to grid cell coordinates
	int x = FMath::FloorToInt((relativePos.X + sphereRadius) * cellSizeInverse);
	int y = FMath::FloorToInt((relativePos.Y + sphereRadius) * cellSizeInverse);
	int z = FMath::FloorToInt((relativePos.Z + sphereRadius) * cellSizeInverse);

	// based on row major order so different coordinates wont get the same index
	// x one cell, y row of cells, z all layers
	int index = x + y * gridSize + z * gridSize * gridSize;

	return index;
}

FVector Grid::GetCellCentre(int cellIndex)
{
	// calculate cell position in grid
	int x = cellIndex % cellsPerSide;				   // gives column pos in current row
	int y = (cellIndex / cellsPerSide) % cellsPerSide; // gives row pos in current layer
	int z = cellIndex / (cellsPerSide * cellsPerSide); // gives layer

	FVector gridCorner = sphereCentre - sphereRadius;  // minimum corner of grid
	FVector cellPos = gridCorner + FVector(x * cellSize, y * cellSize, z * cellSize); // minimum corner of cell
	FVector centre = cellPos + halfCellSize;  

	return centre;
}
