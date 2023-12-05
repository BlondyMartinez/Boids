// Fill out your copyright notice in the Description page of Project Settings.


#include "Predator.h"
#include "Boid.h"
#include "BoidManager.h"
#include "BoidManagerParameters.h"

// Sets default values
APredator::APredator()
{
	massInverse = 1 / 1.5f;
	// create root component
	root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(root);

	// create and attach static mesh component
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cone"));
	UStaticMesh* coneMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cone.cone'")).Object;
	mesh->SetStaticMesh(coneMesh);
	mesh->AttachToComponent(root, FAttachmentTransformRules::KeepRelativeTransform);

	// set relative rotation of the mesh so the tip of the cone faces the direction its moving towards
	mesh->SetRelativeRotation(FRotator(270, 0, 0));

	mesh->SetWorldScale3D(FVector(1.5f));
}

// Called when the game starts or when spawned
void APredator::BeginPlay()
{
	Super::BeginPlay();
	
}

void APredator::UpdatePredator(float DeltaTime)
{
	FVector targetVelocity = ApplyContainment();

	prey = manager->GetClosestBoid(this);
	if (prey != nullptr) {
		targetVelocity += Pursue(prey);
	}

	targetVelocity.Normalize();

	// calculate acceleration
	FVector force = targetVelocity * parameters->predatorSpeed - currentVelocity;
	FVector acceleration = force * massInverse;
	
	// update velocity and pos
	currentVelocity += acceleration * DeltaTime;
	FVector location = GetActorLocation() + currentVelocity * DeltaTime;

	SetActorLocation(location);

	// rotate root component to align with direction
	FVector coneDirection = currentVelocity.GetSafeNormal();
	root->SetWorldRotation(coneDirection.Rotation());
	
}

FVector APredator::Pursue(class ABoid* boid)
{
	FVector toBoid = boid->GetActorLocation() - GetActorLocation();
	float distance = toBoid.Size();

	FVector pursuitVelocity;
	if (distance < parameters->predatorSightRadius) pursuitVelocity = toBoid;
	else {
		//predict future position of pursued
		float predictionTime = FMath::Min(distance / (boid->speed + parameters->predatorSpeed), 5);
		FVector futurePos = boid->GetActorLocation() + boid->currentVelocity * predictionTime;

		//move to futurepos
		pursuitVelocity = futurePos - GetActorLocation();
	}

	return pursuitVelocity;
}

FVector APredator::ApplyContainment()
{
	FVector toCentre = manager->sphereCentre - GetActorLocation();
	float distance = toCentre.Size();

	if (distance > manager->sphereRadius) {
		// soft boundary
		float force = FMath::Clamp((distance - manager->sphereRadius) / 500, 0, 1);
		FVector correction = toCentre.GetSafeNormal() * (distance - manager->sphereRadius);
		return correction * force * parameters->containmentForce;
	}

	return FVector::ZeroVector;
}

void APredator::SetPredatorMaterial(UMaterialInterface* mat)
{
	mesh->SetMaterial(0, mat);
}

