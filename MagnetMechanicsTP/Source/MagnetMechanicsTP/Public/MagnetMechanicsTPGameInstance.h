// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MagnetMechanicsTPGameInstance.generated.h"

/**
 *
 */
UCLASS()
class MAGNETMECHANICSTP_API UMagnetMechanicsTPGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:

	UMagnetMechanicsTPGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init();

	UFUNCTION(BlueprintCallable)
		void LoadMpMenu();

	UFUNCTION(Exec)
		void Host();

	UFUNCTION(Exec)
		void Join(const FString& Address);

private:
	TSubclassOf<class UUserWidget> MpMenuClass;

};
