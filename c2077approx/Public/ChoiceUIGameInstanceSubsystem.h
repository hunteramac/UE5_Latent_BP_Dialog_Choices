// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ChoiceUIGameInstanceSubsystem.generated.h"

DECLARE_DELEGATE_OneParam(FCommonMessagingResultDelegate, int /* Result */);

/**
 * 
 */
UCLASS()
class C2077APPROX_API UChoiceUIGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UChoiceUIGameInstanceSubsystem() { }

	UFUNCTION(BlueprintCallable)
	void UIUserChoice(int Choice);

	virtual void ShowConfirmation(TArray<FText> Actions, FCommonMessagingResultDelegate ResultCallback = FCommonMessagingResultDelegate());

	UPROPERTY(BlueprintReadWrite)
	bool testAccessible;

	UPROPERTY(BlueprintReadOnly)
	TArray<FText> DisplayActions;

private:
	FCommonMessagingResultDelegate OnResultCallback;
};
