// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerMenu.h"

#include "Components/Button.h"
#include "Components/EditableTextBox.h"

bool UMultiplayerMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(Host != nullptr)) return false;
	Host->OnClicked.AddDynamic(this, &UMultiplayerMenu::HostServer);

	if (!ensure(Join != nullptr)) return false;
	Join->OnClicked.AddDynamic(this, &UMultiplayerMenu::JoinServer);

	return true;
}

void UMultiplayerMenu::SetMenuInterface(IMenuInterface* OvrMenuInterface)
{
	this->MenuInterface = OvrMenuInterface; //uses -> since the name is ambiguous (the property or the class)
}

//HOST
void UMultiplayerMenu::HostServer()
{
	//UE_LOG(LogTemp, Warning, TEXT("Hosting a server"));
	if (MenuInterface != nullptr)
		MenuInterface->Host();
}

//JOIN
void UMultiplayerMenu::JoinServer()
{
	//UE_LOG(LogTemp, Warning, TEXT("Joining a server"));
	if (MenuInterface != nullptr)
	{
		if (!ensure(IPField != nullptr)) return;
		//FString Address = IPField->GetText().ToString();
		const FString& Address = IPField->GetText().ToString();
;		MenuInterface->Join(Address);
	}	
}

//DISPLAY THE MENU
void UMultiplayerMenu::Setup()
{
	this->AddToViewport();
	//MpMenu->bIsFocusable = false;

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeUIOnly InputModeData;
	//this function acts as a converter since it needs a SWidget but we use a UWidget (for the UMG):
	InputModeData.SetWidgetToFocus(this->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	//Call the SetInputMode
	PlayerController->SetInputMode(InputModeData);

	//Make the cursor visible
	PlayerController->bShowMouseCursor = true;
}

//DEACTIVATE THE MENU SO THAT INPUTS WORK
void UMultiplayerMenu::DeactivateMenu()
{
	this->RemoveFromViewport();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeGameOnly InputModeData;
	PlayerController->SetInputMode(InputModeData);

	PlayerController->bShowMouseCursor = false;
}

