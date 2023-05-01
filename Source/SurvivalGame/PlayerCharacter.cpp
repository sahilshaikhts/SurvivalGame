// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "WeaponSystem/Weapon.h"
#include <Kismet/GameplayStatics.h>
#include <Kismet/KismetMathLibrary.h>

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	m_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	m_mesh->SetupAttachment(GetRootComponent());
	
	m_weaponSocket = CreateDefaultSubobject<USceneComponent>("WeaponSocket");
	m_weaponSocket->SetupAttachment(m_mesh);

	m_springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	m_springArm->SetupAttachment(GetRootComponent());
	m_springArm->TargetArmLength = 600.0f;

	m_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	m_camera->SetupAttachment(m_springArm);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	AActor* gun=GetWorld()->SpawnActor<AWeapon>(m_gunBP);
	gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale);
	gun->SetActorRelativeLocation(m_weaponSocket->GetRelativeLocation());

	m_gun = dynamic_cast<AWeapon*>(gun);

	m_playerController = Cast<APlayerController>(GetController());

	//Reset camera's pitch temporarily to get forward and right vector directions.
	FRotator cameraOGRotation = m_camera->GetComponentRotation();

	m_camera->SetWorldRotation(FRotator(0, cameraOGRotation.Yaw, cameraOGRotation.Roll));

	m_forwardDirection = m_camera->GetForwardVector();
	m_rightDirection = m_camera->GetRightVector();

	m_camera->SetWorldRotation(cameraOGRotation);

	if (m_playerController)
	{
		m_playerController->bShowMouseCursor = true;
	}
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateCameraRotaion();
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("move_forward"), this, &APlayerCharacter::OnInputMoveForward);
	PlayerInputComponent->BindAxis(TEXT("move_sideWays"), this, &APlayerCharacter::OnInputMoveSideways);
	PlayerInputComponent->BindAxis(TEXT("look_horizontal"), this, &APlayerCharacter::OnMouseMove);
	PlayerInputComponent->BindAxis(TEXT("look_vertical"), this, &APlayerCharacter::OnMouseMove);

	PlayerInputComponent->BindAction(TEXT("UseWeapon"),IE_Pressed, this, &APlayerCharacter::UseWeapon);
}

void APlayerCharacter::UpdateCameraRotaion()
{
	FVector targetDirection = GetDirectionToCursor(GetActorLocation());
	
	m_playerController->SetControlRotation(targetDirection.Rotation());
}

FVector APlayerCharacter::GetDirectionToCursor(FVector aDirectionFrom)
{
	FHitResult hit;
	FVector dirToCursor = FVector::Zero();

	if (m_playerController->GetHitResultUnderCursor(ECC_Visibility, false, hit))
	{
		hit.ImpactPoint.Z = aDirectionFrom.Z;
		dirToCursor = hit.ImpactPoint - aDirectionFrom;
		dirToCursor.Normalize();

	}
	return dirToCursor;
}

void APlayerCharacter::UseWeapon()
{
	m_gun->Fire(GetDirectionToCursor(m_gun->GetMuzzleWorldLocation()));
}
void APlayerCharacter::OnInputMoveForward(float value)
{
	AddMovementInput(m_forwardDirection, value * m_speed);
}
void APlayerCharacter::OnInputMoveSideways(float value)
{
	AddMovementInput(m_rightDirection, value* m_speed);
}

void APlayerCharacter::OnMouseMove(float value)
{
	//UpdateCameraRotaion();

}


