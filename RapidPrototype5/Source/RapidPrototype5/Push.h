// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

#include "Push.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RAPIDPROTOTYPE5_API UPush : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPush();
	ACharacter* OwnerCharacter;
	UCapsuleComponent* body;
	FTimerHandle timeHandle;
	float countdownTime;
	float distance = 100;
	float force = 300;

	//isExtended from BP
	bool IsExtended;
	//object's location in BP
	UPROPERTY(BlueprintReadWrite, Category="ThirdPersonCharacter")
	FVector targetLocation;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;	
	
	void Interacte();

	void CalPushDistance();

	void EndPush();

	UFUNCTION()
	void PushBack(FVector origin, FVector target);

};
