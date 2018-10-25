// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDFPS_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent & OwnerComp,	uint8 * NodeMemory) override;

protected:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
		FBlackboardKeySelector IndexKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
		FBlackboardKeySelector WaypointKey;

private:
	TArray<AActor*> PatrolPoints;

	UBlackboardComponent* Blackboard;

	int32 Index;

	void GetPatrolPoints(UBehaviorTreeComponent& OwnerComp);
	void SetNextWaypoint();
	void SetNextIndex();
};
