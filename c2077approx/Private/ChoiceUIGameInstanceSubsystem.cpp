// Fill out your copyright notice in the Description page of Project Settings.

#include "ChoiceUIGameInstanceSubsystem.h"

void UChoiceUIGameInstanceSubsystem::ShowConfirmation() {
	//We need to write something here to prove this method is running when called
	//Debug out here
	
	UE_LOG(LogTemp, Warning, TEXT("Show dialog choices to player"));

	//One option logs to screen
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("show dialog choices to player"));
	}
}