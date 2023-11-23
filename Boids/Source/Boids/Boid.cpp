// Fill out your copyright notice in the Description page of Project Settings.


#include "Boid.h"
#include "BoidManager.h"

// Sets default values
ABoid::ABoid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	UStaticMesh* sphereMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'")).Object;
	mesh->SetStaticMesh(sphereMesh);
	SetRootComponent(mesh);

}

// Called when the game starts or when spawned
void ABoid::BeginPlay()
{
	Super::BeginPlay();
	
}

FVector ABoid::Seek(FVector pos)
{
	FVector newVelocity = pos - GetActorLocation();
	newVelocity.Normalize();
	return newVelocity;
}

FVector ABoid::Flee(FVector pos)
{
	FVector newVelocity = GetActorLocation() - pos;
	newVelocity.Normalize();
	return newVelocity;
}

// called from BoidManager
void ABoid::UpdateBoid(float DeltaTime)
{
	FVector targetVelocity = FVector::ZeroVector;

	if (waitCounter > 0) {
		waitCounter -= DeltaTime;
	}

	FVector closestBoidPos = manager->ClosestBoidPosition(this);
	if (manager->tagged == this) {
		targetVelocity = Seek(closestBoidPos);
		targetVelocity *= manager->chaserMultiplier;
	}
	else {
		targetVelocity = Flee(closestBoidPos);
	}

	FVector newForce = targetVelocity - currentVelocity;
	currentVelocity += newForce * DeltaTime;

	FVector location = GetActorLocation();
	location += currentVelocity * speed * DeltaTime;

	SetActorLocation(location);
}


// Called every frame
void ABoid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

