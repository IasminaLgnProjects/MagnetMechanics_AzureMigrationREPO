// Fill out your copyright notice in the Description page of Project Settings.


#include "MagnetMechanicsTPGameInstance.h"

#include "Engine/Engine.h"

#include "PressurePlate.h"

#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

//Constructor
UMagnetMechanicsTPGameInstance::UMagnetMechanicsTPGameInstance(const FObjectInitializer& ObjectInitializer)
{
	//UE_LOG(LogTemp, Warning, TEXT("Game instance"));

	//UI - Get a reference to the blueprint menu Widget 
	// UPDATE IT WITH THE PATH OF THE WIDGET
	ConstructorHelpers::FClassFinder<UUserWidget>MpMenuBPClass(TEXT("/Game/Content/UI/WBP_MultiplayerMenu.WBP_MultiplayerMenu_C"));
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
	UUserWidget* MpMenu = CreateWidget<UUserWidget>(this, MpMenuClass);
	if (!ensure(MpMenu != nullptr)) return;

	MpMenu->AddToViewport();

	//DELETE In case of error (change name): MainMenu->bIsFocusable = true;

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeUIOnly InputModeData;
	//this function acts as a converter since it needs a SWidget but we use a UWidget (for the UMG)
	InputModeData.SetWidgetToFocus(MpMenu->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	//Call the SetInputMode
	PlayerController->SetInputMode(InputModeData);

	//Make the cursor visible
	PlayerController->bShowMouseCursor = true;
}


void UMagnetMechanicsTPGameInstance::Host()
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/ThirdPerson/Maps/MultiplayerMap?listen");
}

void UMagnetMechanicsTPGameInstance::Join(const FString& Address)
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}