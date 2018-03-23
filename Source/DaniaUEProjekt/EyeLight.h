// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "Engine/TriggerVolume.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"

#include "EyeLight.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTriggered);



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DANIAUEPROJEKT_API UEyeLight : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEyeLight();

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume* pressurePlate;
	UPROPERTY(EditAnywhere)
		AActor* triggerType;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		

	UPROPERTY(BlueprintAssignable)
		FOnTriggered OnTriggered;
};
