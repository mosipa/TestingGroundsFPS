// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Classes/AIController.h"
#include "PatrolPointComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	Blackboard = OwnerComp.GetBlackboardComponent();

	GetPatrolPoints(OwnerComp);
	if (PatrolPoints.Num() == 0) { return EBTNodeResult::Aborted; }

	SetNextWaypoint();
	SetNextIndex();
	
	return EBTNodeResult::Succeeded;
}

void UChooseNextWaypoint::GetPatrolPoints(UBehaviorTreeComponent& OwnerComp)
{
	auto BTOwner = Cast<AAIController>(OwnerComp.GetOwner())->GetPawn();
	auto PPComponent = BTOwner->GetComponentByClass(UPatrolPointComponent::StaticClass());
	if (!PPComponent) { UE_LOG(LogTemp, Warning, TEXT("PPC not found")); return; }

	PatrolPoints = Cast<UPatrolPointComponent>(PPComponent)->GetPatrolPoints();
}

void UChooseNextWaypoint::SetNextWaypoint()
{
	Index = Blackboard->GetValueAsInt(IndexKey.SelectedKeyName);
	auto ArrayEl = PatrolPoints[Index];
	Blackboard->SetValueAsObject(FName("NextWaypoint"), ArrayEl);
}

void UChooseNextWaypoint::SetNextIndex()
{
	auto NewIndex = (Index + 1) % PatrolPoints.Num();
	Blackboard->SetValueAsInt(FName("NextWaypointIndex"), NewIndex);
}