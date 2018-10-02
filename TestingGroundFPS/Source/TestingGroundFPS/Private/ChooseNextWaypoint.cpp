// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Classes/AIController.h"
#include "PatrollingGuard.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	Blackboard = OwnerComp.GetBlackboardComponent();

	GetPatrolPoints(OwnerComp);
	SetNextWaypoint();
	SetNextIndex();
	
	return EBTNodeResult::Succeeded;
}

void UChooseNextWaypoint::GetPatrolPoints(UBehaviorTreeComponent& OwnerComp)
{
	auto BTOwner = Cast<APatrollingGuard>(Cast<AAIController>(OwnerComp.GetOwner())->GetPawn());
	PatrolPoints = BTOwner->GetPatrolPoints();
}

void UChooseNextWaypoint::SetNextWaypoint()
{
	Index = Blackboard->GetValueAsInt(IndexKey.SelectedKeyName);
	auto ArrayEl = PatrolPoints[Index];
	Blackboard->SetValueAsObject(FName("NextWaypoint"), ArrayEl);
}

void UChooseNextWaypoint::SetNextIndex()
{
	Blackboard->SetValueAsInt(FName("NextWaypointIndex"), (Index + 1) % PatrolPoints.Num());
}