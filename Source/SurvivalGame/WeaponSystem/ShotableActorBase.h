// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShotableActorBase.generated.h"

UCLASS()
class SURVIVALGAME_API AShotableActorBase : public ACharacter
{
	GENERATED_BODY()
	
public:	
	AShotableActorBase();

protected:
	void OnHit();

	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void OnShot(FVector hitDirection);
	virtual void Damage(float amount);
	
};
