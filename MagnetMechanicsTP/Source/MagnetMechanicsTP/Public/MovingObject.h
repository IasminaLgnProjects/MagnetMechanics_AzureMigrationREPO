// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingObject.generated.h"

/**
 * 
 */
UCLASS()
class MAGNETMECHANICSTP_API AMovingObject : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMovingObject();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		float speed = 30;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;

	void AddActivePpTrigger();
	void RemoveActivePpTrigger();

private:
	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;

	UPROPERTY(EditAnywhere)
		int activePpTriggers = 1;
};
