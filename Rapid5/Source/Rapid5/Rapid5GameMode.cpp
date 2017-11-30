// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Rapid5GameMode.h"
#include "Rapid5Character.h"
#include "UObject/ConstructorHelpers.h"

ARapid5GameMode::ARapid5GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
