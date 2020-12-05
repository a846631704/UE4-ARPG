// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
class AMainPlayer;
UCLASS()
class PROJECTBLEAK_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	float Vertical_Input;
	float Horizontal_Input;
public:
	UFUNCTION()
	void Move_Forward(float Value);
	UFUNCTION()
	void Move_Right(float Value);

	void AddYawInput(float Value) override;
	void AddPitchInput(float Value) override;
private:
	class AMainPlayer* Player;

public:
	AMainPlayerController();

	void Tick(float DeltaTime) override;

protected:
	void BeginPlay() override;

public:
	void SetupInputComponent() override;

	

	

	
};
