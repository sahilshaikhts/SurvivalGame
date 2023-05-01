// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_MoveInAttackRange.h"
#include"BehaviorTree/BlackBoardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"

UTask_MoveInAttackRange::UTask_MoveInAttackRange()
{
    m_navSystem= UNavigationSystemV1::GetCurrent(GetWorld());
}

EBTNodeResult::Type UTask_MoveInAttackRange::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    UBlackboardComponent* blackBoard=OwnerComp.GetBlackboardComponent();

    blackBoard->SetValueAsVector(key_targetLocation,)
    return EBTNodeResult::Succeeded;
}
