// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include"ProjectBleak/MiniCamera.h"
#include"ProjectBleak/Main_UserWidget.h"
#include"Engine/Datatable.h"
#include"PlayerInfo.h"
#include "Components/SceneCaptureComponent2D.h"
#include "UObject/ConstructorHelpers.h"
#include"Animation/AnimInstance.h"
#include "Engine/SkeletalMesh.h"
// Sets default values
AMainPlayer::AMainPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	/*��������������������������������������������������������Component���ɤȳ��ڻ���������������������������������������������������������*/

	static ConstructorHelpers::FObjectFinder<USkeletalMesh>Player_Mesh(TEXT("SkeletalMesh'/Game/Resources/GKnight/Meshes/SK_GothicKnight_VA.SK_GothicKnight_VA'"));
	GetMesh()->SetSkeletalMesh(Player_Mesh.Object);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -88));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	static ConstructorHelpers::FClassFinder<UAnimInstance>Anim(TEXT("AnimBlueprint'/Game/PlayerContent/AnimBp_MainPlayer.AnimBp_MainPlayer_C'"));
	GetMesh()->SetAnimInstanceClass(Anim.Class);

	Portrait_Camera = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("Portrait_Camera"));
	Portrait_Camera->SetupAttachment(GetMesh(), "head");
	Portrait_Camera->SetRelativeRotation(FRotator(90.0f, 0.f, -90.f));
	Portrait_Camera->SetRelativeLocation(FVector(0.f, 70.f, 0.f));


	GreatSword_Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GreatSword_Mesh"));
	GreatSword_Mesh->SetupAttachment(GetMesh(), FName("WeaponMesh"));


	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring_Arm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 400.f;

	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 15.0f;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow_Camera"));
	FollowCamera->SetupAttachment(SpringArm);
	/*��������������������������������������������������������Component���ɤȳ��ڻ���������������������������������������������������������*/
}

// Called when the game starts or when spawned
void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
	Main_UserWidget=CreateWidget<UMain_UserWidget>(GetWorld(), LoadClass<UMain_UserWidget>(this, TEXT("WidgetBlueprint'/Game/UMG/WBP_Main_UI.WBP_Main_UI_C'")));
	if (Main_UserWidget)Main_UserWidget->AddToViewport();
	ReadData();
}

// Called every frame
void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}



void AMainPlayer::SetCurrentHp(float DeltaHp)
{
	CurrentHp += DeltaHp; 
	//UMG��HPBar��ͬ�ڤ���
	if(Main_UserWidget)Main_UserWidget->SetHPProgressBar(CurrentHp / TotalHp);
}

void AMainPlayer::SetCurrentMp(float DeltaMp)
{
	CurrentHp += DeltaMp;
	//UMG��MPBar��ͬ�ڤ���
	if(Main_UserWidget)Main_UserWidget->SetMPProgressBar(CurrentMp / TotalMp);
}

void AMainPlayer::SetCurrentStamina(float DeltaStamina)
{
	CurrentStamina += DeltaStamina;
	//UMG��StaminaBar��ͬ�ڤ���
	if(Main_UserWidget)Main_UserWidget->SetStaminaProgressBar(CurrentStamina / TotalStamina);
}

void AMainPlayer::SetCurrentExp(float DeltaCurrentExp)
{
	CurrentExp += DeltaCurrentExp;
	//UMG��ExpBar��ͬ�ڤ���
	if(Main_UserWidget)Main_UserWidget->SetExpProgressBar(CurrentExp / TotalExp);
}

void AMainPlayer::SetLevel(int Level)
{
	CurrentLevel = Level;
	//UMG�Υ�٥��ʾ��ͬ�ڤ���
	if(Main_UserWidget)Main_UserWidget->SetLevelText(FText::AsNumber(Level));
}




void AMainPlayer::ReadData()
{
	//�ץ쥤��`�Υ��Ʃ`������ä�
	UDataTable*PlayerInfo = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("DataTable'/Game/PlayerContent/PlayerInfo.PlayerInfo'")));
	if (PlayerInfo==nullptr)
	{
		return;
	}
	//���`���_ʼ�Υץ쥤��`���Ʃ`�����O��
	FMainPlayerInfo*Row= PlayerInfo->FindRow<FMainPlayerInfo>(TEXT("S1"), TEXT("PlayerInfo error"));
	if (Row)
	{
		PlayerName = Row->PlayerName;
		TotalHp = Row->StartHp;
		TotalMp = Row->StartMp;
		TotalStamina = Row->StartStamina;

		CurrentHp = TotalHp;
		CurrentMp = TotalMp;
		CurrentStamina = TotalStamina;

		
		SetCurrentHp(0);
		SetCurrentMp(0);
		SetCurrentStamina(0);
		SetCurrentExp(0);
		SetLevel(1);
	}
	
}