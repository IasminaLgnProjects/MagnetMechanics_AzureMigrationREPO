// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerMenu.h"

#include "Components/Button.h"

bool UMultiplayerMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(Host != nullptr)) return false;
	Host->OnClicked.AddDynamic(this, &UMultiplayerMenu::HostServer);

	return true;
}

void UMultiplayerMenu::SetMenuInterface(IMenuInterface* OvrMenuInterface)
{
	this->MenuInterface = OvrMenuInterface; //uses -> since the name is ambiguous (the property or the class)
}

void UMultiplayerMenu::HostServer()
{
	//UE_LOG(LogTemp, Warning, TEXT("Hosting a server"));
	if (MenuInterface != nullptr)
		MenuInterface->Host();
}