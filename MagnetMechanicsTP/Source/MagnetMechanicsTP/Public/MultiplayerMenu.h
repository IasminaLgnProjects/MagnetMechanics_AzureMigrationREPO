// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MultiplayerMenu.generated.h"

/**
 * 
 */
UCLASS()
class MAGNETMECHANICSTP_API UMultiplayerMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetMenuInterface(IMenuInterface* MenuInterface);

	void Setup();
	void DeactivateMenu();
	
protected:
	virtual bool Initialize();

private:
	//UI
	UPROPERTY(meta = (BindWidget))
	class UButton* Host;

	UPROPERTY(meta = (BindWidget))
	class UButton* Join;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* IPField;
	

	//functions
	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void JoinServer();

	IMenuInterface* MenuInterface;
};
