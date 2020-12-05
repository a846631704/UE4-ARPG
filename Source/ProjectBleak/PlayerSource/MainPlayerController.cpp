// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"
#include"MainPlayer.h"

AMainPlayerController::AMainPlayerController()
{
	/*bShowMouseCursor = true;*/
}

void AMainPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainPlayerController::BeginPlay()
{
	Player = Cast<AMainPlayer>(GetPawn());
}

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveForward", this, &AMainPlayerController::Move_Forward);
	InputComponent->BindAxis("MoveRight", this, &AMainPlayerController::Move_Right);
	InputComponent->BindAxis("Turn", this, &AMainPlayerController::AddYawInput);
	InputComponent->BindAxis("Lookup", this, &AMainPlayerController::AddPitchInput);
}

void AMainPlayerController::Move_Forward(float Value)
{
	Vertical_Input = Value;
	if (Value != 0&& Player!=nullptr)
	{

		//����ȥ�`��`��Yaw�����ä�
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
		//�ޥȥ�å����Ƿ����ä�
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		Player->AddMovementInput(Direction, Value);
		
	}
}

void AMainPlayerController::Move_Right(float Value)
{
	Horizontal_Input = Value;
	if (Value != 0 && Player != nullptr)
	{
		//����ȥ�`��`��Yaw�����ä�
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
		//�ޥȥ�å����Ƿ����ä�
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		Player->AddMovementInput(Direction, Value);
	}
}

void AMainPlayerController::AddYawInput(float Value)
{
	if (Value != 0 && Player != nullptr)
	{
		Super::AddYawInput(Value);
	}
}

void AMainPlayerController::AddPitchInput(float Value)
{
	if (Value != 0 && Player != nullptr)
	{
		Super::AddPitchInput(Value);
	}
}
