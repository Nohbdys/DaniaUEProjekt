// Fill out your copyright notice in the Description page of Project Settings.

#include "EyeLight.h"


// Sets default values for this component's properties
UEyeLight::UEyeLight()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEyeLight::BeginPlay()
{
	Super::BeginPlay();

	triggerType = GetWorld()->GetFirstPlayerController()->GetPawn();

	
}


// Called every frame
void UEyeLight::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (pressurePlate && pressurePlate->IsOverlappingActor(triggerType))
	{
		OnTriggered.Broadcast();
	}
}

