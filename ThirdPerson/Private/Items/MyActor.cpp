// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/MyActor.h"
#include "DrawDebugHelpers.h"
#include "ThirdPerson/DebugMacros.h"
#include "Components/SphereComponent.h"

// Sets default values
AMyActor::AMyActor() {
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

	// Store the location to the pointer
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent")); // This function returns a pointer to the object
	RootComponent = ItemMesh; // Garbage collected to root pointer, root points to ItemMesh now

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay() {
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AMyActor::OnSphereOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AMyActor::OnSphereEndOverlap);
}

float AMyActor::TransformedSin() {
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AMyActor::TransformedCos() {
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

void AMyActor::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const FString OtherActorName = OtherActor->GetName();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 30.f, FColor::Red, OtherActorName);
	}
}

void AMyActor::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	const FString OtherActorName = FString("Ending Overlap with: ") + OtherActor->GetName();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 30.f, FColor::Blue, OtherActorName);
	}
}

// Called every frame
void AMyActor::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	// DRAW_SPHERE_SingleFrame(GetActorLocation());
	// DRAW_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);
	//
	// // Template function
	// FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);
	//
	// DRAW_POINT_SingleFrame(AvgVector);
}
