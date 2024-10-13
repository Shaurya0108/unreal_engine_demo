// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/MyActor.h"
#include "DrawDebugHelpers.h"

// Define the sphere's parameters as a macro
#define DRAW_SPHERE_PARAMS(World, Location) \
    DrawDebugSphere(World, Location, 25.0f, 24, FColor::Red, false, 30.0f)

// Sets default values
AMyActor::AMyActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    Super::BeginPlay();
    
    UE_LOG(LogTemp, Warning, TEXT("AMyActor::BeginPlay"));

    if (GEngine) {
        GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Red, TEXT("On Screen Debug"));
    }

    UWorld* World = GetWorld();

    if (World) {
        FVector Location = GetActorLocation();
        DRAW_SPHERE_PARAMS(World, Location);  // Use the macro here
    }
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    UE_LOG(LogTemp, Warning, TEXT("Delta Time: %f"), DeltaTime);

    if (GEngine) {
        FString message = FString::Printf(TEXT("AMyActor::Tick: %f"), DeltaTime);
        GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Red, message);
    }
}

