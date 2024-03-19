// Fill out your copyright notice in the Description page of Project Settings.

#include "AsyncChoice.h"
#include "Engine/GameInstance.h"


UAsyncChoice::UAsyncChoice(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UAsyncChoice* UAsyncChoice::ShowActionChoices(UObject* InWorldContextObject, TArray<FText> Actions)
{
	UAsyncChoice* Action = NewObject<UAsyncChoice>();
	//Action->WorldContextObject = InWorldContextObject;

	//make the UI
	//Action->Descriptor = UCommonGameDialogDescriptor::CreateConfirmationYesNo(Title, Message);
	//Action->RegisterWithGameInstance(InWorldContextObject);

	return Action;
}


void UAsyncChoice::Activate()
{
	//dummy setup, immediately returns 0. We will change this by delaying handle confirmation
	//Need to get MyGameInstanceSubsystem and call it's 'special method'
	HandleConfirmationResult(0);
	return;
}

void UAsyncChoice::HandleConfirmationResult(int ChoiceMade)
{
	OnResult.Broadcast(0);

	SetReadyToDestroy();
}