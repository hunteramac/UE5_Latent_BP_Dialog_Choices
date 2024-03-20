// Fill out your copyright notice in the Description page of Project Settings.

#include "AsyncChoice.h"

#include "Kismet/GameplayStatics.h"

#include "Engine/GameInstance.h"
#include "ChoiceUIGameInstanceSubsystem.h"

UAsyncChoice::UAsyncChoice(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UAsyncChoice* UAsyncChoice::ShowActionChoices(UObject* InWorldContextObject, TArray<FText> Actions)
{
	UAsyncChoice* Choices = NewObject<UAsyncChoice>();
	Choices->WorldContextObject = InWorldContextObject;
	Choices->Actions = Actions;
	
	return Choices;
}

void UAsyncChoice::Activate()
{

	//get world context
	UWorld* World = WorldContextObject->GetWorld();

	//use context to get game instance
	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(World);

	//use game instance to get our communication subsystem
	if (UChoiceUIGameInstanceSubsystem* MySubsystem = GameInstance->GetSubsystem<UChoiceUIGameInstanceSubsystem>()) {

		//setup callback function for UI
		FCommonMessagingResultDelegate ResultCallback = FCommonMessagingResultDelegate::CreateUObject(this, &UAsyncChoice::HandleConfirmationResult);

		MySubsystem->ShowConfirmation(Actions, ResultCallback); //should be passing callback + choices for UI here
		return;
	}

	//something went wrong
	HandleConfirmationResult(0);
	return;
}

void UAsyncChoice::HandleConfirmationResult(int ChoiceMade)
{
	OnResult.Broadcast(ChoiceMade);

	SetReadyToDestroy();
}