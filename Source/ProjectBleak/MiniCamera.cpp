// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniCamera.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Kismet/GameplayStatics.h"
#include"PlayerSource/MainPlayer.h"
AMiniCamera::AMiniCamera() 
{

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = true;
	PrimaryActorTick.TickGroup = TG_PrePhysics;
	
}

void AMiniCamera::BeginPlay()
{
	Super::BeginPlay();
	
	Player=Cast<AMainPlayer>(UGameplayStatics::GetPlayerPawn(this,0));
	/*SetActorLocation(FVector(Player->GetActorLocation().X, Player->GetActorLocation().Y, GetActorLocation().Z));*/
}

void AMiniCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



	
	Outside_Tick();
	
}

void AMiniCamera::Outside_Tick()
{
	//¥Þ¥Ã¥×ÓÃ¤Î¥«¥á¥é¤ò¥×¥ì¥¤¥ä©`¤ÎÎ»ÖÃ¤ËÔOÖÃ
	if (Player)
	{

		SetActorLocation(FVector(Player->GetActorLocation().X, Player->GetActorLocation().Y, GetActorLocation().Z));

	}
}
