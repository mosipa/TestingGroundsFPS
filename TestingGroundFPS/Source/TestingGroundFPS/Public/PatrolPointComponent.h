// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolPointComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDFPS_API UPatrolPointComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	TArray<AActor*> GetPatrolPoints();

private:
	UPROPERTY(EditAnywhere, Category = "Patrol")
		TArray<AActor*> PatrolPoints;
};
