// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingObject.h"

AMovingObject::AMovingObject()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingObject::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	//GlobalStartLocation = GetLocalLocation();
	//GlobalTargetLocation = GetTransform();

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}


void AMovingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (activePpTriggers > 0)
	{
		if (HasAuthority())
		{
			//object's location
			FVector Location = GetActorLocation();

			//the distance = the lenght of the Vector
			float totalJourneyLenght = (GlobalTargetLocation - GlobalStartLocation).Size();
			float travelledJourneyLenght = (Location - GlobalStartLocation).Size();

			if (travelledJourneyLenght >= totalJourneyLenght)
			{
				FVector ContainerForSwap = GlobalStartLocation;
				GlobalStartLocation = GlobalTargetLocation;
				GlobalTargetLocation = ContainerForSwap;
			}

			//REMOVEDFVector GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
			//FVector Direction = (GlobalTargetLocation - Location).GetSafeNormal();
			FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();

			//Location += FVector(speed * DeltaTime, 0, 0);
			Location += speed * DeltaTime * Direction;
			SetActorLocation(Location);
		}
	}


	//create an Fvector for the current location
	//direction = target location - current location
	//apply movement
}

void AMovingObject::AddActivePpTrigger()
{
	activePpTriggers++;
}
void AMovingObject::RemoveActivePpTrigger()
{
	if (activePpTriggers > 0) activePpTriggers--;
}
