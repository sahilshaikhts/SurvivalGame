// Fill out your copyright notice in the Description page of Project Settings.


#include "ShotableActorBase.h"

AShotableActorBase::AShotableActorBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AShotableActorBase::BeginPlay()
{
	Super::BeginPlay();
}

void AShotableActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AShotableActorBase::OnShot(FVector hitDirection)
{
}

void AShotableActorBase::Damage(float amount)
{
}

