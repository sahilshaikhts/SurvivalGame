// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIController_enemy.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVALGAME_API AAIController_enemy : public AAIController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "BehaviorTree")
	class UBehaviorTree* m_behaviourTree;
	UPROPERTY(EditDefaultsOnly,Category="BehaviorTree")
	class UBehaviorTreeComponent* m_behaviourTreeComp;
	UPROPERTY(EditDefaultsOnly, Category = "BehaviorTree")
	class UBlackboardComponent* m_blackBoard;


public:
	AAIController_enemy();
	void BeginPlay() override;
	void OnPossess(APawn* pawn) override;

	class UBlackboardComponent* GetBlackBoard();
};
