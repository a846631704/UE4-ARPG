// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerBaseSkill.generated.h"
UENUM()
enum class ETargetTypes :uint8
{
	Self,          //�Է�
	SelectedEnemy, //���`���åȔ�
	SelectedArea,  //���`���åȹ���
	AreaAroundSelf, //�Է����x
	Missile         //��ϵ
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
