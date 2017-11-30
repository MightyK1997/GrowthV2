// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "RapidPrototype5GameMode.h"
#include "RapidPrototype5Character.h"
#include "UObject/ConstructorHelpers.h"

ARapidPrototype5GameMode::ARapidPrototype5GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
