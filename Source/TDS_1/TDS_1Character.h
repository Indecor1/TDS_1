// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Types.h"
#include "TDS_1Character.generated.h"

UCLASS(Blueprintable)
class ATDS_1Character : public ACharacter
{
	GENERATED_BODY()

public:
	ATDS_1Character();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;
public:
	//Character properties

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	EMovementState MovementState = EMovementState::Run_State;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FCharacterSpeed MovementInfo;
	//Character state properties
	UPROPERTY(BlueprintReadWrite, Category = "Character State")
	bool IsAiming;
	UPROPERTY(BlueprintReadWrite, Category = "Character State")
	bool IsSprinting;
	UPROPERTY(BlueprintReadWrite, Category = "Character State")
	bool IsWalking;
	UPROPERTY(BlueprintReadWrite, Category = "Character State")
	bool IsRunning = true;

	//Stamina system

	UPROPERTY(BlueprintReadWrite, Category = "Stamina")
	float CurrentStamina;

	UPROPERTY(BlueprintReadWrite, Category = "Stamina")
	float MaxStamina;

	UPROPERTY(BlueprintReadWrite, Category = "Stamina")
	float StaminaReplenishRate;

	UPROPERTY(BlueprintReadWrite, Category = "Stamina")
	float StaminaDrainRate;

	float StaminaTimer;
	float StaminaReplenishInterval;

	UFUNCTION()
	void UpdateStamina(float DeltaSeconds);
	//Movement

	UFUNCTION()
	void InputAxisY(float Value);
	UFUNCTION()
	void InputAxisX(float Value);

	float AxisX = 0.0f;
	float AxisY = 0.0f;

	// Tick Func
	UFUNCTION()
	void MovementTick(float DeltaTime);

	//Character Functions

	UFUNCTION(BlueprintCallable)
	void CharacterUpdate();
	UFUNCTION(BlueprintCallable)
	void ChangeMovementState();
};

