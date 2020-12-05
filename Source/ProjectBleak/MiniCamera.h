// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/SceneCapture2D.h"
#include "MiniCamera.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBLEAK_API AMiniCamera : public ASceneCapture2D
{
	GENERATED_BODY()

	AMiniCamera();

	class AMainPlayer*Player;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	void Tick(float DeltaTime) override;

	void Outside_Tick();
};
