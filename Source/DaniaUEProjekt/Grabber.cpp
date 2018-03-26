// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "DrawDebugHelpers.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	playerController = GetWorld()->GetFirstPlayerController();
	inputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	physicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (inputComponent)
	{
		inputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		inputComponent->BindAction("GrabRelease", IE_Pressed, this, &UGrabber::Released);

		UE_LOG(LogTemp, Warning, TEXT("INPUT COMPONENT FOUND"));

	}
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	MoveObject();
	GetPhysicsBody();


}

FHitResult UGrabber::GetPhysicsBody()
{

	playerController->GetPlayerViewPoint(location, rotation);
	FVector LineTraceEnd = location + rotation.Vector() * reach;
	FHitResult hit;
	FCollisionQueryParams TraceParam(FName(TEXT("")), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType(hit, location, LineTraceEnd, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParam);
	AActor* actorHit = hit.GetActor();

	if (actorHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("I just hit: %s "), *actorHit->GetName());
	}

	return hit;
}

void UGrabber::Grab()
{

	UE_LOG(LogTemp, Warning, TEXT("GRAB KEY PRESSED"));
	auto hitResult = GetPhysicsBody();
	auto componentToGrab = hitResult.GetComponent();
	auto actorHit = hitResult.GetActor();
	if (actorHit)
	{
		AActor* owner = componentToGrab->GetOwner();
		physicsHandle->GrabComponentAtLocationWithRotation(componentToGrab, NAME_None, owner->GetActorLocation(), owner->GetActorRotation());
	}

}
void UGrabber::Released()
{
	UE_LOG(LogTemp, Warning, TEXT("GRAB KEY RELEASED"));

	physicsHandle->ReleaseComponent();

}
void UGrabber::MoveObject()
{
	FVector location;
	FRotator rotation;
	// ...
	playerController->GetPlayerViewPoint(OUT location, OUT rotation);
	FVector LineTraceEnd = location + rotation.Vector() * reach;
	if (physicsHandle->GrabbedComponent)
	{
		physicsHandle->SetTargetLocation(LineTraceEnd);
	}
}