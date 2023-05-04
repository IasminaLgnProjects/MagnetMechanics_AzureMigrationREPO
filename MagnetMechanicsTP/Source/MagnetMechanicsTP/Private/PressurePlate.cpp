// Fill out your copyright notice in the Description page of Project Settings.


#include "PressurePlate.h"

#include "Components/BoxComponent.h"

#include "MovingObject.h"

// Sets default values
APressurePlate::APressurePlate()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PpTriggerVolume = CreateDefaultSubobject<UBoxComponent>(FName("PpTriggerVolume"));

	//check if the root is not null, otherwise return from the method
	if (!ensure(PpTriggerVolume != nullptr)) return;

	RootComponent = PpTriggerVolume;

	PpTriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &APressurePlate::OnOverlapBegin);
	PpTriggerVolume->OnComponentEndOverlap.AddDynamic(this, &APressurePlate::OnOverlapEnd);
}

// Called when the game starts or when spawned
void APressurePlate::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APressurePlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APressurePlate::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("Activated"));
		for (AMovingObject* Platform : ObjectsToTrigger)
		{
			Platform->AddActivePpTrigger();
		}
	}
}

void APressurePlate::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("Deactivated"));
		for (AMovingObject* Platform : ObjectsToTrigger)
		{
			Platform->RemoveActivePpTrigger();
		}
	}
}
