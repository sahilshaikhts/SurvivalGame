// Fill out your copyright notice in the Description page of Project Settings.


#include "AIController_enemy.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

AAIController_enemy::AAIController_enemy()
{
	ConstructorHelpers::FObjectFinder<UBehaviorTree> assest_bt(TEXT("/Script/AIModule.BehaviorTree'/Game/BehaviourTree/Enemy_1/BT_Enemy_1.BT_Enemy_1'"));

	if (assest_bt.Succeeded())
		m_behaviourTree = assest_bt.Object;

	m_behaviourTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	m_blackBoard = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void AAIController_enemy::BeginPlay()
{
	if(m_behaviourTree)
	RunBehaviorTree(m_behaviourTree);

	m_behaviourTreeComp->StartTree(*m_behaviourTree);
}

void AAIController_enemy::OnPossess(APawn* pawn)
{
	if (m_blackBoard)
	{
		m_blackBoard->InitializeBlackboard(*m_behaviourTree->BlackboardAsset);
	}
}

UBlackboardComponent* AAIController_enemy::GetBlackBoard()
{
	return nullptr;
}
