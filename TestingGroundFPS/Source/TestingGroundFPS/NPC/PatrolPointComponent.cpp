// Fill out your copyright notice in the Description page of Project Settings.

#include "PatrolPointComponent.h"

TArray<AActor*> UPatrolPointComponent::GetPatrolPoints()
{
	return PatrolPoints;
}
