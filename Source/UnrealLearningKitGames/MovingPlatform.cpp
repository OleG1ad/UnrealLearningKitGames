// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	FString Name = GetName();

	UE_LOG(LogTemp, Display, TEXT("Start moving: %s"), *Name);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);

	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{

	// Reverse direction of motion if gone too far
	if (ShouldPlatformReturn())
	{
		// float OverShoot = DistanceMoved - MoveDistance;
		// FString Name = GetName();
		// UE_LOG(LogTemp, Display, TEXT("OverShoot: %s %f"), *Name, OverShoot);

		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		// Move platform forwards
		// Get current location
		auto CurrentLocation = GetActorLocation();
		// Add vector to that location
		CurrentLocation += (PlatformVelocity * DeltaTime);
		// Set the location
		SetActorLocation(CurrentLocation);
		// Send platform back if gone too far
	}
}

void AMovingPlatform::RotatePlatform(float DT)
{
	UE_LOG(LogTemp, Display, TEXT("Rotating..."), *GetName());
}

bool AMovingPlatform::ShouldPlatformReturn()
{
	// Check how far we've moved
	return GetDistanceMoved() > MoveDistance;
}

float AMovingPlatform::GetDistanceMoved()
{
	return FVector::Dist(StartLocation, GetActorLocation());
}