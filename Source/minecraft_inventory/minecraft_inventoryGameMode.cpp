// Copyright Epic Games, Inc. All Rights Reserved.

#include "minecraft_inventoryGameMode.h"
#include "minecraft_inventoryHUD.h"
#include "minecraft_inventoryCharacter.h"
#include "UObject/ConstructorHelpers.h"

Aminecraft_inventoryGameMode::Aminecraft_inventoryGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = Aminecraft_inventoryHUD::StaticClass();
}
