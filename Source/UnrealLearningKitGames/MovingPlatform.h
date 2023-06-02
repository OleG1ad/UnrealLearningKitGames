// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class UNREALLEARNINGKITGAMES_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FVector PlatformVelocity = FVector(100, 0, 0);

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	float MoveDistance = 100;

	// UPROPERTY(VisibleAnywhere, Category = "Moving Platform")
	// float DistanceMoved = -1;

	FVector StartLocation;

	// UPROPERTY(EditAnywhere)
	// int32 MyInt2 = 99;

	// UPROPERTY(EditAnywhere)
	// float InputFloatA = 0;

	// UPROPERTY(EditAnywhere)
	// float InputFloatB = 0;

	// UPROPERTY(EditAnywhere)
	// float A_Plus_B_Float = 0;

	// UPROPERTY(EditAnywhere)
	// bool MyBool = true;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn();

	float GetDistanceMoved();

};
