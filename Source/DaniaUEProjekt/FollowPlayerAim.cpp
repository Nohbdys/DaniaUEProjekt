// Fill out your copyright notice in the Description page of Project Settings.

#include "FollowPlayerAim.h"


// Sets default values
AFollowPlayerAim::AFollowPlayerAim()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFollowPlayerAim::BeginPlay()
{
	Super::BeginPlay();
	playerController = GetWorld()->GetFirstPlayerController();
}

// Called every frame
void AFollowPlayerAim::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	playerController->GetPlayerViewPoint(location, rotation);

}

