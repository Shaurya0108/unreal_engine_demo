// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/MyActor.h"
#include "DrawDebugHelpers.h"
#include "ThirdPerson/DebugMacros.h"

// Sets default values
AMyActor::AMyActor() {
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay() {
	Super::BeginPlay();
}

float AMyActor::TransformedSin() {
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AMyActor::TransformedCos() {
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

// Called every frame
void AMyActor::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	DRAW_SPHERE_SingleFrame(GetActorLocation());
	DRAW_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);

	// Template function
	FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);

	DRAW_POINT_SingleFrame(AvgVector);
}
