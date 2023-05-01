// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponSystem/ShotableActorBase.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class SURVIVALGAME_API APlayerCharacter : public AShotableActorBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		float m_speed;
	UPROPERTY(EditAnywhere)
		float m_rotateSpeed;
	UPROPERTY(EditAnywhere)
		FVector2D m_mouseSensitivity;
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* m_mesh;

	UPROPERTY(EditAnywhere)
	class USceneComponent* m_weaponSocket;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* m_camera;
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* m_springArm;
	

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AWeapon> m_gunBP;
	class AWeapon* m_gun;

private:
	FVector2D m_mouseInput;
	FVector m_forwardDirection, m_rightDirection;
	APlayerController* m_playerController;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void UseWeapon();
	void OnInputMoveForward(float value);
	void OnInputMoveSideways(float value);
	void OnMouseMove(float value);

	FVector GetDirectionToCursor(FVector aDirectionFrom);
public:	
	APlayerCharacter();

	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

private:
	void UpdateCameraRotaion();
};
