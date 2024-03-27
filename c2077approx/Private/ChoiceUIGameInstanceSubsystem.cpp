// Fill out your copyright notice in the Description page of Project Settings.

#include "ChoiceUIGameInstanceSubsystem.h"

//Should be called by UI when a button is pressed by user
//For prototyping, this function is public, but in future should be limited to only be callable by UI
void UChoiceUIGameInstanceSubsystem::UIUserChoice(int Choice) {
	OnResultCallback.Execute(Choice);
}

void UChoiceUIGameInstanceSubsystem::ShowConfirmation(TArray<FText> Actions, FCommonMessagingResultDelegate ResultCallback) {
	// Setup ui
	// Insert code that shows choices
	//Store actions as a BP var that UI can read from the subsystem
	DisplayActions = Actions;
	
	//store callback
	OnResultCallback = ResultCallback;
}

void UChoiceUIGameInstanceSubsystem::SubsystemShowChoice() {
	OnSubsystemShowChoice.Broadcast();
}