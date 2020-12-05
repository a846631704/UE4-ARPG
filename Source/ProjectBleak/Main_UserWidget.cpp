// Fill out your copyright notice in the Description page of Project Settings.


#include "Main_UserWidget.h"
#include"Components/TextBlock.h"
#include"Components/ProgressBar.h"
//UI§Œ±Ì æ§Ú‘O∂®
bool UMain_UserWidget::Initialize()
{
	if (!Super::Initialize()) { return false; }
	LevelText=Cast<UTextBlock>(GetWidgetFromName("Level"));
	HPProgressBar = Cast<UProgressBar>(GetWidgetFromName("WBP_Hp"));
	MPProgressBar = Cast<UProgressBar>(GetWidgetFromName("WBP_Mp"));
	StaminaProgressBar = Cast<UProgressBar>(GetWidgetFromName("WBP_Stamina"));
	ExpProgressBar = Cast<UProgressBar>(GetWidgetFromName("WBP_Exp"));
	return true;
}
void UMain_UserWidget::SetLevelText(FText Text)
{
	if (LevelText)LevelText->SetText(Text);
}

void UMain_UserWidget::SetHPProgressBar(float Percent)
{
	if(HPProgressBar)HPProgressBar->SetPercent(Percent);
}

void UMain_UserWidget::SetMPProgressBar(float Percent)
{
	if(MPProgressBar)MPProgressBar->SetPercent(Percent);
}

void UMain_UserWidget::SetStaminaProgressBar(float Percent)
{
	if(StaminaProgressBar)StaminaProgressBar->SetPercent(Percent);
}

void UMain_UserWidget::SetExpProgressBar(float Percent)
{
	if(ExpProgressBar)ExpProgressBar->SetPercent(Percent);
}