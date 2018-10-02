// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	auto Blackboard = OwnerComp.GetBlackboardComponent();
	
	auto IndexToPrint = Blackboard->GetValueAsInt(IndexKey.SelectedKeyName);

	UE_LOG(LogTemp, Warning, TEXT("next waypoint index: %i"), IndexToPrint);
	return EBTNodeResult::Succeeded;
}


