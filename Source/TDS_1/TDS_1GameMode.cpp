// Copyright Epic Games, Inc. All Rights Reserved.

#include "TDS_1GameMode.h"
#include "TDS_1PlayerController.h"
#include "TDS_1Character.h"
#include "UObject/ConstructorHelpers.h"

ATDS_1GameMode::ATDS_1GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATDS_1PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/TDS/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}