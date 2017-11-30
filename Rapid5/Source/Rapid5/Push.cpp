// Fill out your copyright notice in the Description page of Project Settings.

#include "Push.h"


// Sets default values for this component's properties
UPush::UPush()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	
}


// Called when the game starts
void UPush::BeginPlay()
{
	Super::BeginPlay();
	
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	OwnerCharacter->InputComponent->BindAction("Push", IE_Released, this, &UPush::Interacte);
	OwnerCharacter->InputComponent->BindAction("Push", IE_Repeat, this, &UPush::CalPushDistance);

	body = OwnerCharacter->GetCapsuleComponent();

	countdownTime = 1.0f;

}


// Called every frame
void UPush::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UPush::Interacte()
{
	//get controller
	APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	
	//ray cast
	if (controller != nullptr)
	{
		//initialize hit info
		FHitResult hit(ForceInit);

		controller->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, hit);

		//determine if hit
		if (hit.IsValidBlockingHit())
		{
			//determine if it can be grappled
			//if (hit.GetActor()->ActorHasTag(FName(TEXT("CanGrapple"))))
			//{
			UE_LOG(LogTemp, Warning, TEXT("Push %f"), distance);
			//calculate target position
			FVector objectPosition, position, target, direction;
			objectPosition = hit.GetActor()->GetTransform().GetLocation();
			position = OwnerCharacter->GetActorLocation();
			//calculate direction
			direction = FVector::VectorPlaneProject((position - objectPosition), FVector::UpVector);
			direction.Normalize();
			target = position + direction * distance;
			//UE_LOG(LogTemp, Warning, TEXT("direction is %f, %f"), direction.X, direction.Y);
			//UE_LOG(LogTemp, Warning, TEXT("target position is %f, %f"), target.X, target.Y);

			//set timer
			FTimerDelegate timerDel;
			timerDel.BindUFunction(this, FName("PushBack"), position, target);
			OwnerCharacter->GetWorldTimerManager().SetTimer(timeHandle, timerDel, 0.01f, true);


			//add force
			

			//}
			//else
			//{
			//	UE_LOG(LogTemp, Warning, TEXT("Cannot Grapple"));
		//	}

		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No hit"));
		}

	}

	distance = 100;
}

void UPush::CalPushDistance()
{
	if(distance <= 400)
		distance += 20;
}

void UPush::PushBack(FVector origin, FVector target)
{

	//move
	FVector position = FMath::Lerp(target ,origin, countdownTime);
	OwnerCharacter->SetActorLocation(position);
	//UE_LOG(LogTemp, Warning, TEXT("New position is %f, %f"), position.X , position.Y);

	countdownTime -= OwnerCharacter->GetWorldTimerManager().GetTimerElapsed(timeHandle);
	//UE_LOG(LogTemp, Warning, TEXT("time is %f, %f"), OwnerCharacter->GetWorldTimerManager().GetTimerElapsed(timeHandle));
	
	//clear
	if (countdownTime <= 0)
	{
		countdownTime = 1.0f;
		OwnerCharacter->GetWorldTimerManager().ClearTimer(timeHandle);
		UE_LOG(LogTemp, Warning, TEXT("End pushing"));
	}
}


