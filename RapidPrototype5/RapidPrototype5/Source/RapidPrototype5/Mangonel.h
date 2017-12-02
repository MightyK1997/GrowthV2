// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Mangonel.generated.h"

UCLASS()
class RAPIDPROTOTYPE5_API AMangonel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMangonel();

	UPROPERTY(EditAnywhere)
	AActor* pivotActor;

	UPROPERTY(EditAnywhere)
	float force;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
