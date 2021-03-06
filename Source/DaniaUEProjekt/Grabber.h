// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "Components/InputComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DANIAUEPROJEKT_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

private:
	APlayerController * playerController;
	FVector location;
	FRotator rotation;
	int reach = 210;
	int addedReach = 0;

	UPhysicsHandleComponent* physicsHandle = nullptr;

	UInputComponent* inputComponent = nullptr;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	FHitResult GetPhysicsBody();
	void Grab();
	void Released();
	void MoveObject();
	void PullAway();
	void PullCloser();

	
};
