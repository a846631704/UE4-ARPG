// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "PlayerInfo.generated.h"

USTRUCT()
struct FMainPlayerInfo :public FTableRowBase 
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "PlayerInfo")
	FString PlayerName;
	UPROPERTY(EditAnywhere, Category = "PlayerInfo")
	float StartHp;
	UPROPERTY(EditAnywhere, Category = "PlayerInfo")
	float StartMp;
	UPROPERTY(EditAnywhere, Category = "PlayerInfo")
	float StartStamina;
	UPROPERTY(EditAnywhere, Category = "PlayerInfo")
	float StartExp;

};