// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncChoice.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCommonMessagingResultMCDelegate, int, choice);

/**
 * 
 */
UCLASS()
class C2077APPROX_API UAsyncChoice : public UBlueprintAsyncActionBase
{
	//GENERATED_BODY()
	GENERATED_UCLASS_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UAsyncChoice* ShowActionChoices(
		UObject* InWorldContextObject, TArray<FText> Actions
	);

	virtual void Activate() override;
public:
	UPROPERTY(BlueprintAssignable)
	FCommonMessagingResultMCDelegate OnResult;
private:
	void HandleConfirmationResult(int ChoiceMade);
};
