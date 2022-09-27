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
	startLocation = GetActorLocation();

	FString myString = "Custom Message";
	UE_LOG(LogTemp, Display, TEXT("Console log: %s"), *myString);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}
void AMovingPlatform::MovePlatform(float deltaTime) 
{
	FVector currentLocation = GetActorLocation();
	currentLocation = currentLocation + (platformVelocity * deltaTime);
	SetActorLocation(currentLocation);

	distanceMoved = FVector::Dist(startLocation, currentLocation);

	if (distanceMoved > moveDistance)
	{
		FVector moveDirection = platformVelocity.GetSafeNormal();
		startLocation = startLocation + moveDirection * moveDistance;
		SetActorLocation(startLocation);
		platformVelocity = -platformVelocity;
	}
}
void AMovingPlatform::RotatePlatform(float deltaTime) 
{
	UE_LOG(LogTemp, Display, TEXT("Rotating platform!"));
}

