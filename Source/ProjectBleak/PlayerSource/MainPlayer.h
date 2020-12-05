// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#define EnemyTrace ECC_GameTraceChannel1

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainPlayer.generated.h"

USTRUCT()
struct FSkillStage
{
	GENERATED_BODY()

	float Range;  //¥¹¥­¥ë¤Î¹ ‡ì

	float Damage; //¥¹¥­¥ë¤Î¥À¥á©`¥¸

	float MisiileSpeed; //¥¹¥­¥ë¤Îïw¤Ö¥¹¥Ó©`¥È

	float MpCost;  //Mp‚ŽÏûºÄ
};

UCLASS()
class PROJECTBLEAK_API AMainPlayer : public ACharacter
{
	GENERATED_BODY()
protected:
	UPROPERTY(VisibleAnywhere, Category = "PlayerInfo")
	FString PlayerName;
	UPROPERTY(VisibleAnywhere, Category = "PlayerInfo")
	float TotalHp;
	UPROPERTY(VisibleAnywhere, Category = "PlayerInfo")
	float TotalMp;
	UPROPERTY(VisibleAnywhere, Category = "PlayerInfo")
	float TotalStamina;
	UPROPERTY(VisibleAnywhere, Category = "PlayerInfo")
	float TotalExp;

	UPROPERTY(VisibleAnywhere, Category = "PlayerInfo")
	float CurrentHp;
	UPROPERTY(VisibleAnywhere, Category = "PlayerInfo")
	float CurrentMp;
	UPROPERTY(VisibleAnywhere, Category = "PlayerInfo")
	float CurrentStamina;
	UPROPERTY(VisibleAnywhere, Category = "PlayerInfo")
	float CurrentExp;
	UPROPERTY(VisibleAnywhere, Category = "PlayerInfo")
	float CurrentLevel;
public:

	void SetCurrentHp(float DeltaHp);
	void SetCurrentMp(float DeltaMp);
	void SetCurrentStamina(float DeltaStamina);
	void SetCurrentExp(float DeltaCurrentExp);
	void SetLevel(int Level);

	FORCEINLINE float GetCurrentHp() { return CurrentHp; }
	FORCEINLINE float GetCurrentMp() { return CurrentMp; }
	FORCEINLINE float GetCurrentStamina() { return CurrentStamina; }
	FORCEINLINE void SetPlayerName(FString Name) { PlayerName=Name; }
	FORCEINLINE FString GetPlayerName() { return PlayerName; }

public:
	void ReadData();

public:
	class UMain_UserWidget * Main_UserWidget;
	UPROPERTY(VisibleAnywhere, Category = "Camera Setting")
	class USpringArmComponent * SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Camera Setting")
	class UCameraComponent * FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon Setting")
	class USkeletalMeshComponent *GreatSword_Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon Setting")
	class UBoxComponent *GreatSword_Collision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon Setting")
	class USceneCaptureComponent2D* Portrait_Camera;

	//class AMiniCamera*MiniMapCamera;
	

public:
	// Sets default values for this character's properties
	AMainPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	
};
