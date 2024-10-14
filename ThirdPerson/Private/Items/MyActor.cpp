// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/MyActor.h"
#include "DrawDebugHelpers.h"
#include "ThirdPerson/ThirdPerson.h"

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
    
    // Log in console
    UE_LOG(LogTemp, Warning, TEXT("AMyActor::BeginPlay"));
    
    // Log on game screen
    if (GEngine) {
        GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Red, TEXT("On Screen Debug"));
    }
    
    // Define the world
    UWorld* World = GetWorld();

    if (World) {
        // Draw sphere around the actor
        FVector Location = GetActorLocation();
        DRAW_SPHERE_PARAMS(World, Location);
        
        // Draw vector pointing from the front of the actor
        DrawDebugLine(World, Location, Location + (GetActorForwardVector() * 100.f), FColor::Red, true);
    }
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    // Log the delta time to the console
    UE_LOG(LogTemp, Warning, TEXT("Delta Time: %f"), DeltaTime);

    // Log the delta time to the screen for 5 seconds
    if (GEngine) {
        FString message = FString::Printf(TEXT("AMyActor::Tick: %f"), DeltaTime);
        GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Red, message);
    }
}

