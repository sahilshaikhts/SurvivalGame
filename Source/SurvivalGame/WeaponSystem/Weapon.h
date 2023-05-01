#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Weapon.generated.h"

UCLASS()
class SURVIVALGAME_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere)
	int m_ammo;
	int m_rounds;
	int m_clipSize;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AProjectile> m_projectile;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* m_weaponMesh;
	UPROPERTY(EditAnywhere)
	class USceneComponent* m_weaponMuzzle;
protected:
	class UWorld* m_world;
	virtual void BeginPlay() override;

public:	
	AWeapon();
	virtual void Tick(float DeltaTime) override;
	void Fire(FVector direction);
	void Reload();

	FVector GetMuzzleWorldLocation();

};
