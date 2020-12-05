// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerBaseSkill.generated.h"
UENUM()
enum class ETargetTypes :uint8
{
	Self,          //自分
	SelectedEnemy, //ターゲット敵
	SelectedArea,  //ターゲット範囲
	AreaAroundSelf, //自分周辺
	Missile         //弾系
};
UCLASS()
class PROJECTBLEAK_API APlayerBaseSkill : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerBaseSkill();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
