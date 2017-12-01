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
	
	//get character
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	OwnerCharacter->InputComponent->BindAction("Push", IE_Released, this, &UPush::Interacte);
	OwnerCharacter->InputComponent->BindAction("Push", IE_Repeat, this, &UPush::CalPushDistance);

	//get physical body
	body = OwnerCharacter->GetCapsuleComponent();

	//time to active physics
	countdownTime = 1.0f;

}


// Called every frame
void UPush::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UPush::Interacte()
{
	//get IsExtended in BP
	UBoolProperty* boolProp = FindField<UBoolProperty>(OwnerCharacter->GetClass(), TEXT("IsExtended"));
	if (boolProp != nullptr)
	{
		IsExtended = boolProp->GetPropertyValue_InContainer(OwnerCharacter);

	}

	//if not grapple, don't push
	if (!IsExtended)
		return;

	//get object's location in BP
	UScriptStruct* vectorStruct = FindObjectChecked<UScriptStruct>(UObject::StaticClass(), TEXT("Vector"));
	UStructProperty* vectorProp = FindField<UStructProperty>(OwnerCharacter->GetClass(), TEXT("previousLocation"));
	if (vectorStruct != nullptr && vectorProp->Struct == vectorStruct)
	{
		FVector* locationPtr = vectorProp->ContainerPtrToValuePtr<FVector>(OwnerCharacter);
		if (locationPtr != nullptr)
			targetLocation = *locationPtr;
	}

	FVector position, target, direction;
	position = OwnerCharacter->GetActorLocation();

	//calculate direction
	direction = FVector::VectorPlaneProject((position - targetLocation), FVector::UpVector);
	direction.Normalize();
	target = position + direction * distance;
	//UE_LOG(LogTemp, Warning, TEXT("direction is %f, %f"), direction.X, direction.Y);
	//UE_LOG(LogTemp, Warning, TEXT("target position is %f, %f"), target.X, target.Y);

	//set timer
	FTimerDelegate timerDel;
	timerDel.BindUFunction(this, FName("PushBack"), position, target);
	//OwnerCharacter->GetWorldTimerManager().SetTimer(timeHandle, timerDel, 0.01f, true);

	//set delay
	OwnerCharacter->GetWorldTimerManager().SetTimer(timeHandle, this, &UPush::EndPush, 1.0f, false);

	//use force
	if (body != nullptr)
	{
		//set physics
		body->SetSimulatePhysics(true);
		body->BodyInstance.bLockRotation = true;

		//add force
		direction.Z = 1;
		body->AddImpulse(direction * body->GetBodyInstance()->GetBodyMass() * force);

	}


	//get controller
	/* Don't need raycast
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
			//OwnerCharacter->GetWorldTimerManager().SetTimer(timeHandle, timerDel, 0.01f, true);
			
			//set delay
			OwnerCharacter->GetWorldTimerManager().SetTimer(timeHandle, this, &UPush::EndPush, 1.0f, false);

			//use force
			if (body != nullptr)
			{
				//set physics
				body->SetSimulatePhysics(true);
				body->BodyInstance.bLockRotation = true;

				//add force
				direction.Z = 1;
				body->AddImpulse(direction * body->GetBodyInstance()->GetBodyMass() * force);
				
			}

		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No hit"));
		}

	}*/

	distance = 100;
	force = 300;
}

void UPush::CalPushDistance()
{
	if (distance <= 400)
		distance += 20;
	//increase force
	if (force <= 600)
		force += 20;
}

void UPush::PushBack(FVector origin, FVector target)
{

	//move
	FVector position = FMath::Lerp(target ,origin, countdownTime);
	OwnerCharacter->SetActorLocation(position);

	countdownTime -= OwnerCharacter->GetWorldTimerManager().GetTimerElapsed(timeHandle);
	
	//clear
	if (countdownTime <= 0)
	{
		countdownTime = 1.0f;
		OwnerCharacter->GetWorldTimerManager().ClearTimer(timeHandle);
		UE_LOG(LogTemp, Warning, TEXT("End pushing"));
	}
}

void UPush::EndPush()
{
	body->SetSimulatePhysics(false);
}


