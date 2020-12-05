// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_AnimInstance.h"
#include"MainPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include"MainPlayerController.h"
void UPlayer_AnimInstance::UpdateAnimationProperties()
{
	if (PlayerRef == nullptr)
	{
		PlayerRef = Cast<AMainPlayer>(TryGetPawnOwner());
	}
	if (PlayerController == nullptr&&PlayerRef!=nullptr)
	{
		PlayerController = Cast<AMainPlayerController>(PlayerRef->GetController());
	}
	if (PlayerRef&&PlayerController)
	{
		//移動アニメーション更新
		const FVector SpeedVector = PlayerRef->GetVelocity();
		const FVector PlanarSpeed = FVector(SpeedVector.X, SpeedVector.Y, 0.0f);
		Vertical_Speed = PlanarSpeed.Size();
		//プレイヤーの入力状態を確認
		if (PlayerController->Vertical_Input == 0&& PlayerController->Horizontal_Input==0)
		{
			b_Player_Input = false;
		}
		else 
		{
			b_Player_Input = true;
		}
		/*if (b_Player_Input==true&&FRo(PlayerController->GetActorRotation - PlayerRef->GetActorRotation).ABS>90)
		{

		}*/

	}
}
