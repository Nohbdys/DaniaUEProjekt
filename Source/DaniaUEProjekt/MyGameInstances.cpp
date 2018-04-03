// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstances.h"
#include "MoviePlayer.h"

void UMyGameInstances::Init()
{
	Super::Init();

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UMyGameInstances::BeginLoadingScreen);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UMyGameInstances::EndLoadingScreen);
}

void UMyGameInstances::BeginLoadingScreen(const FString & MapName)
{
	if (!IsRunningDedicatedServer())
	{
		FLoadingScreenAttributes LoadingScreen;
		LoadingScreen.bAutoCompleteWhenLoadingCompletes = false;
		LoadingScreen.WidgetLoadingScreen = FLoadingScreenAttributes::NewTestLoadingScreenWidget();

		GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
	}
}

void UMyGameInstances::EndLoadingScreen(UWorld * InLoadedWorld)
{
}
