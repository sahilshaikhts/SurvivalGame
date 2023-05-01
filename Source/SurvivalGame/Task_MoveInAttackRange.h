// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"

#include "Task_MoveInAttackRange.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVALGAME_API UTask_MoveInAttackRange : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
private:
	class UNavigationSystemV1* m_navSystem;
public:
	UTask_MoveInAttackRange();
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BB_Keys")
		FName key_targetLocation;
};
