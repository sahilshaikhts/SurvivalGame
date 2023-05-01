// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class SURVIVALGAME_API AProjectile : public AActor
{
	GENERATED_BODY()

public:

protected:
	UPROPERTY(EditAnywhere)
	float m_lifeSpan = 1.0f;

	class USphereComponent* m_collider;

	class UProjectileMovementComponent* m_projectile;

protected:
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult); 
public:
	AProjectile();
	virtual void Tick(float DeltaTime) override;

};


