// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

// Inlcude before Bird.generated
#include "Components/CapsuleComponent.h"
#include "Bird.generated.h"

UCLASS()
class THIRDPERSON_API ABird : public APawn
{
	GENERATED_BODY()

public:
	ABird();
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Capsule;
};
