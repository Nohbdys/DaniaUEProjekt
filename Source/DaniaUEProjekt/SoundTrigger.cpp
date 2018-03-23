// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundTrigger.h"


// Sets default values for this component's properties
USoundTrigger::USoundTrigger()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USoundTrigger::BeginPlay()
{
	Super::BeginPlay();

	triggerType = GetWorld()->GetFirstPlayerController()->GetPawn();

}


// Called every frame
void USoundTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (pressurePlate && pressurePlate->IsOverlappingActor(triggerType))
	{
		onSoundRequest.Broadcast();
	}
}

