// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/MyActor.h"
#include "DrawDebugHelpers.h"
#include "ThirdPerson/DebugMacros.h"

// Sets default values
AItem::AItem() {
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AItem::BeginPlay() {
	Super::BeginPlay();
}

float AItem::TransformedSin() {
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCos() {
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

// Called every frame
void AItem::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	DRAW_SPHERE_SingleFrame(GetActorLocation());
	DRAW_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);

	FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);
	DRAW_POINT_SingleFrame(AvgVector);
}
