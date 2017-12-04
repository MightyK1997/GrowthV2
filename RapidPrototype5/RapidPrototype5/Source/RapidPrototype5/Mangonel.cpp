// Fill out your copyright notice in the Description page of Project Settings.

#include "Mangonel.h"


// Sets default values
AMangonel::AMangonel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMangonel::BeginPlay()
{
	Super::BeginPlay();

	UStaticMeshComponent* mesh = Cast<UStaticMeshComponent>(GetRootComponent());
	if (mesh)
	{
		mesh->AddImpulseAtLocation(FVector(0, 0, force) * mesh->GetMass(), pivotActor->GetActorLocation());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Root component is not a static mesh."));
	}
	
}

// Called every frame
void AMangonel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

