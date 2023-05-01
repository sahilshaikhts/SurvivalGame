#include "Enemy.h"

AEnemy::AEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemy::OnShot(FVector hitDirection)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Shot: "));
}

void AEnemy::Damage(float amount)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("damaged: "));
}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


