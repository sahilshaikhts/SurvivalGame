// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WeaponSystem/ShotableActorBase.h"
#include "Enemy.generated.h"

UCLASS()
class SURVIVALGAME_API AEnemy : public AShotableActorBase
{
	GENERATED_BODY()

public:
	AEnemy();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void OnShot(FVector hitDirection) override;
	virtual void Damage(float amount)override;

};
