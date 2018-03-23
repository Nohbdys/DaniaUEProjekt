// Fill out your copyright notice in the Description page of Project Settings.

#include "RockingMovement.h"


// Sets default values for this component's properties
URockingMovement::URockingMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URockingMovement::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URockingMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

