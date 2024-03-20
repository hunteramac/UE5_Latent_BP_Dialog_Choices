// Fill out your copyright notice in the Description page of Project Settings.

#include "ChoiceUIGameInstanceSubsystem.h"

//Called by UI when a button is pressed
//For prototyping, this function is public, but in future should be limited to only be callable by UI
void UChoiceUIGameInstanceSubsystem::UIUserChoice(int Choice) {
	//UE_LOG(LogTemp, Warning, TEXT("Subsystem called by BP"));
	//StoredCallback.Execute(Choice);
}

void UChoiceUIGameInstanceSubsystem::ShowConfirmation(TArray<FText> Actions, FCommonMessagingResultDelegate ResultCallback) {
	//We need to write something here to prove this method is running when called
	//Debug out here
	
	//FText TestText = Actions[0];
	//FString TestString = TestText.ToString();

	//UE_LOG(LogTemp, Warning, TEXT("Show dialog choices to player"));

	////One option logs to screen
	//if (GEngine)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TestString);
	//}

	//Store ResultCallback
	//StoredCallback = ResultCallback;

	//experimental, immediately cause async node caller to handle confirmation (choice 0)
	ResultCallback.Execute(1/*hard codes which choice player makes from actions*/);
}