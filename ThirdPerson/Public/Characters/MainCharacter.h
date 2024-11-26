// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Items/MyActor.h"
#include "CharacterTypes.h"

#include "MainCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class AMyActor;
class UAnimMontage;
class AWeapon;

UCLASS()
class THIRDPERSON_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMainCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void Jump() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable)
	void SetWeaponCollisionEnabled(ECollisionEnabled::Type CollisionEnabled);
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category=Input)
	UInputMappingContext* MainContext;

	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction* EKeyAction;

	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction* FKeyAction;

	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction* AttackAction;
	
	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction* SprintAction;
	
	void Move(const FInputActionValue& MovementAction);
	void Look(const FInputActionValue& MovementAction);

	/** Call backs for input **/
	void EKeyPressed();
	void FKeyPressed();
	void Attack();
	void Sprint();

	/** 
	* Play montage functions
	*/
	void PlayAttackMontage();
	
	UFUNCTION(BlueprintCallable)
    void AttackEnd();
    bool CanAttack();

	void PlayEquipMontage(const FName& SectionName);
	bool CanDisArm();
	bool CanArm();

	UFUNCTION(BlueprintCallable)
	void Disarm();
	
	UFUNCTION(BlueprintCallable)
	void Arm();
	
	UFUNCTION(BlueprintCallable)
	void FinishEquipping();
	
private:
	UPROPERTY(EditAnywhere, Category = "Movement")
	float WalkSpeed = 600.f;
    
	UPROPERTY(EditAnywhere, Category = "Movement")
	float SprintSpeed = 1200.f;

	bool bIsSprinting = false;
	
	int32 CurrentAttackIndex = 0;
	
	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;
	
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	EActionState ActionState = EActionState::EAS_Unoccupied;
	
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleInstanceOnly)
	AMyActor* OverlappingItem;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	AWeapon* EquippedWeapon;

	/** 
	* Animation montages
	*/
	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* AttackMontage;

	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* EquipMontage;

public:
	FORCEINLINE void SetOverlappingItem(AMyActor* Item) { OverlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
};