// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Projectile.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_world = GetWorld();
	
	USceneComponent* root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = root;

	m_weaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("GunMesh");
	m_weaponMesh->SetupAttachment(root);

	
	m_weaponMuzzle= CreateDefaultSubobject<USceneComponent>("WeaponMuzzle");
	m_weaponMuzzle->SetupAttachment(m_weaponMesh);
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWeapon::Fire(FVector direction)
{
	FVector position = this->m_weaponMesh->GetComponentLocation();
	FRotator rotation = direction.Rotation();
	FActorSpawnParameters param;
	param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	
	m_world->SpawnActor<AProjectile>(m_projectile,position, rotation,param);
}

FVector AWeapon::GetMuzzleWorldLocation()
{
	return m_weaponMuzzle->GetComponentLocation();
}
