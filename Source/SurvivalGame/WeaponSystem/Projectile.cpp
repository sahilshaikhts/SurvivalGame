// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include <Components/DrawSphereComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>
#include <SurvivalGame/Enemy.h>
#include "ShotableActorBase.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_collider = CreateDefaultSubobject<USphereComponent>(TEXT("collider"));
	RootComponent = m_collider;
	
	m_projectile = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("projectile"));
	m_projectile->UpdatedComponent = m_collider;
	m_projectile->InitialSpeed = 2000;
	m_projectile->bRotationFollowsVelocity = true;
	m_projectile->MaxSpeed = 2000;
	m_projectile->ProjectileGravityScale = 0;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	InitialLifeSpan = m_lifeSpan;
	m_collider->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::OnOverlapBegin);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		AShotableActorBase* otherCharacter = Cast<AShotableActorBase>(OtherActor);

		if (otherCharacter)
		{
			otherCharacter->OnShot(GetActorForwardVector());
			otherCharacter->Damage(5);
		}
	}
}

