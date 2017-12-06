// Fill out your copyright notice in the Description page of Project Settings.

#include "SwingInArc.h"

using namespace std;


// Sets default values for this component's properties
USwingInArc::USwingInArc()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USwingInArc::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ACharacter>(GetOwner());
	// ...
	
}


// Called every frame
void USwingInArc::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UBoolProperty* boolProp = NULL;

	//UBoolProperty* boolProp = FindField<UBoolProperty>(OwnerCharacter->GetClass(), TEXT("IsHanging"));
	if (boolProp != nullptr)
	{
		IsHanging = boolProp->GetPropertyValue_InContainer(OwnerCharacter);

	}

	//if not grapple, don't push
	if (!IsHanging)
		return;
	else
		CheckForSwing();
	// ...
}

void USwingInArc::CheckForSwing()
{
	if (!Swinging)
	{
		Swinging = true;
	}
	else
	{
		MakeSwingHappen();
	}
}

void USwingInArc::MakeSwingHappen()
{
	float timer = 0.0;
	float distance;
	FVector playerPosition, targetLocation, testVector, newPlayerPosition;
	testVector = FVector(0, 0, -120);
	playerPosition = OwnerCharacter->GetActorLocation();
	UScriptStruct* vectorStruct = FindObjectChecked<UScriptStruct>(UObject::StaticClass(), TEXT("Vector"));
	UStructProperty* vectorProp = FindField<UStructProperty>(OwnerCharacter->GetClass(), TEXT("currentLocation"));

	if (vectorStruct != nullptr && vectorProp->Struct == vectorStruct)
	{
		FVector* locationPtr = vectorProp->ContainerPtrToValuePtr<FVector>(OwnerCharacter);
		targetLocation = *locationPtr;
	}

	distance = sqrt(pow((targetLocation.X - playerPosition.Y), 2) + pow((targetLocation.Y - playerPosition.Y), 2) + pow((targetLocation.Z - playerPosition.Z), 2));


	//if (distance > 500)
	//{
	//	playerPosition = playerPosition + testVector;
	//}
	//else
	//{
	playerPosition += testVector; 
		newPlayerPosition = playerPosition;
		newPlayerPosition.Z += 1;
		newPlayerPosition.X += 1;
		while (newPlayerPosition.Z != playerPosition.Z)
		{
			for (auto i=newPlayerPosition.X; ; i++)
			{
				for (auto k = newPlayerPosition.Z;;k++)
				{
					if ((pow(floor(targetLocation.X) - i , 2) + pow(floor(targetLocation.Z) - k, 2)) == pow(distance,2))
					{
						newPlayerPosition = FVector(i, newPlayerPosition.Y, k);
						OwnerCharacter->SetActorLocation(newPlayerPosition);				
					}
				}
			}
		}
	//}
}

