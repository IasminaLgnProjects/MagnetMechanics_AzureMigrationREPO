// Fill out your copyright notice in the Description page of Project Settings.


#include "MagnetMechanicsTPGameInstance.h"

#include "Engine/Engine.h"

#include "PressurePlate.h"

#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "MultiplayerMenu.h" 

//Constructor
UMagnetMechanicsTPGameInstance::UMagnetMechanicsTPGameInstance(const FObjectInitializer & ObjectInitializer)
{
	//UE_LOG(LogTemp, Warning, TEXT("Game instance"));

	//UI - Get a reference to the blueprint menu Widget 
	ConstructorHelpers::FClassFinder<UUserWidget> MpMenuBPClass(TEXT("/Game/WBP_MultiplayerMenu"));
	if (!ensure(MpMenuBPClass.Class != nullptr)) return;

	MpMenuClass = MpMenuBPClass.Class;
}

void UMagnetMechanicsTPGameInstance::Init()
{
	//UE_LOG(LogTemp, Warning, TEXT("Game instance INIT"));
	UE_LOG(LogTemp, Warning, TEXT("Found class %s"), *MpMenuClass->GetName());
}


void UMagnetMechanicsTPGameInstance::LoadMpMenu()
{
	if (!ensure(MpMenuClass != nullptr)) return;
	//UUserWidget* MpMenu = CreateWidget<UUserWidget>(this, MpMenuClass);
	//UMultiplayerMenu* MpMenu = CreateWidget<UMultiplayerMenu>(this, MpMenuClass);
	MpMenu = CreateWidget<UMultiplayerMenu>(this, MpMenuClass);
	if (!ensure(MpMenu != nullptr)) return;

	/*
		MpMenu->AddToViewport();
	MpMenu->bIsFocusable = true;

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeUIOnly InputModeData;
	//this function acts as a converter since it needs a SWidget but we use a UWidget (for the UMG):
	InputModeData.SetWidgetToFocus(MpMenu->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	//Call the SetInputMode
	PlayerController->SetInputMode(InputModeData);

	//Make the cursor visible
	PlayerController->bShowMouseCursor = true;
	*/

	MpMenu->Setup();

	//Set the menu interface to the current instance
	MpMenu->SetMenuInterface(this);
}


void UMagnetMechanicsTPGameInstance::Host()
{
	//First deactivate the menu so it does not have control over the input
	if (MpMenu != nullptr)
	{
		MpMenu->DeactivateMenu();
	}

	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/ThirdPerson/Maps/MultiplayerMap?listen"); //The ServerTravel is called on the World and moves all players
}

void UMagnetMechanicsTPGameInstance::Join(const FString& Address)
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute); //The ClientTravel is called on each player and moves them individually
}