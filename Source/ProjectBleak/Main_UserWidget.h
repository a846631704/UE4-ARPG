// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Main_UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBLEAK_API UMain_UserWidget : public UUserWidget
{
	GENERATED_BODY()

	class UTextBlock * LevelText;

	class UProgressBar * HPProgressBar;

	class UProgressBar * MPProgressBar;

	class UProgressBar * ExpProgressBar;

	class UProgressBar * StaminaProgressBar;

	virtual bool Initialize() override;
public:
	void SetLevelText(FText Text);

	void SetHPProgressBar(float Percent);

	void SetMPProgressBar(float Percent);

	void SetStaminaProgressBar(float Percent);

	void SetExpProgressBar(float Percent);
};
