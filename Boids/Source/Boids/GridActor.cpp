// Fill out your copyright notice in the Description page of Project Settings.

#include "Boid.h"
#include "Predator.h"
#include "GridActor.h"

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
                FVector cellCentre = startPoint + FVector(x * cellSize, y * cellSize, z * cellSize) + FVector(cellSize * .5f);
                // checks if cell is within sphere since the grid is a bounding box
                if ((cellCentre - sphereCentre).Size() <= sphereRadius) {
                    gridCells.Add(GridCell{ cellCentre, cellSize });
                }
            }
        }
    }

    // give an index to each cell
    int cellIndex = 0;
    for (GridCell cell : gridCells) {
        cell.cellIndex = cellIndex;
        cellIndex++;
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
        // if index is valid add boid to cell boids array
        if (cellIndex >= 0 && cellIndex < gridCells.Num()) {
            gridCells[cellIndex].boids.Add(boid);
        }
    }
    for (APredator* predator : predators) {
        int cellIndex = GetCellIndex(predator->GetActorLocation());
        // if index is valid add predator to cell predators array
        if (cellIndex >= 0 && cellIndex < gridCells.Num()) gridCells[cellIndex].predators.Add(predator);
    }
}

// called from boidmanager
// adds obstacle to every cell it intersects with
void AGridActor::AddObstacleToCell(AActor* obstacle)
{
    if (obstacle != nullptr) {
        FBox obstacleBox = obstacle->GetComponentsBoundingBox(); // get 3d space occupied by obstacle

        // check for intersections since obstacles may occupy more than one cell and add obstacle to each cell it intersects with
        for (GridCell cell : gridCells) {
            FBox cellBox(cell.centre - FVector(cell.size * .5f), cell.centre + FVector(cell.size * 0.5f));
            if (cellBox.Intersect(obstacleBox)) {
                cell.obstacles.Add(obstacle);
            }
        }
    }
}

int AGridActor::GetCellIndex(const FVector& pos)
{
    // world pos to pos within grid
    FVector relativePos = (pos - sphereCentre) / (sphereRadius * 2) + FVector(.5f);
    relativePos *= gridRes;

    // coordinates to indices
    int x = FMath::Clamp(FMath::FloorToInt(relativePos.X), 0, gridRes - 1);
    int y = FMath::Clamp(FMath::FloorToInt(relativePos.Y), 0, gridRes - 1);
    int z = FMath::Clamp(FMath::FloorToInt(relativePos.Z), 0, gridRes - 1);

    // 3d to 1d index
    return x + y * gridRes + z * gridRes * gridRes;
}

TArray<class ABoid*> AGridActor::GetBoidsInCell(int cellIndex)
{
    // if valid cell index return boids in cell
    if (cellIndex >= 0 && cellIndex < gridCells.Num()) {
        return gridCells[cellIndex].boids;
    }
    return TArray<class ABoid*>();
}

TArray<class APredator*> AGridActor::GetPredatorsInCell(int cellIndex)
{
    // if valid cell index return predators in cell
    if (cellIndex >= 0 && cellIndex < gridCells.Num()) {
        return gridCells[cellIndex].predators;
    }
    return TArray<class APredator*>();
}

TArray<AActor*> AGridActor::GetObstaclesInCell(int cellIndex)
{
    // if valid cell index return obstacles in cell
    if (cellIndex >= 0 && cellIndex < gridCells.Num()) {
        return gridCells[cellIndex].obstacles;
    }
    return TArray<AActor*>();
}

TArray<int> AGridActor::GetAdjacentCellIndices(int CurrentCellIndex)
{
    TArray<int> adjacentIndices;
    // calculate number of cells along one axis
    int gridWidth = FMath::RoundToInt(FMath::Pow(gridCells.Num(), 1.f/3.f)); // grid is a cube so cubic root

    // array of possible moves
    TArray<FVector> directions = {
        FVector(-1, 0, 0), // west
        FVector(1, 0, 0),  // east
        FVector(0, -1, 0), // south
        FVector(0, 1, 0),  // north
        FVector(0, 0, -1), // down
        FVector(0, 0, 1),  // up
    };

    // convert 1d index of current cell to 3d coordinates
    int x = CurrentCellIndex % gridWidth;
    int y = (CurrentCellIndex / gridWidth) % gridWidth;
    int z = CurrentCellIndex / (gridWidth * gridWidth);

    // check each direction
    for (FVector direction : directions) {
        // coordinates of adjacent cell
        int newX = x + direction.X;
        int newY = y + direction.Y;
        int newZ = z + direction.Z;

        // if within boundaries convert 3d coordinates back to 1d index and adds it to adjacent indices array
        if (newX >= 0 && newX < gridWidth && 
            newY >= 0 && newY < gridWidth && 
            newZ >= 0 && newZ < gridWidth) {
            int newIndex = newX + newY * gridWidth + newZ * gridWidth * gridWidth;
            adjacentIndices.Add(newIndex);
        }
    }

    return adjacentIndices;
}

void AGridActor::DrawGrid()
{
    for (GridCell gridCell : gridCells) {
        DrawDebugBox(
            GetWorld(),
            gridCell.centre,
            FVector(gridCell.size * .5F),
            FColor::Blue,
            true,
            0.f,
            0,
            .5f
        );
    }
}
