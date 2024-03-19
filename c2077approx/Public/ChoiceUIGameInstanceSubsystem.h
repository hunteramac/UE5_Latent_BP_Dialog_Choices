// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ChoiceUIGameInstanceSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class C2077APPROX_API UChoiceUIGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UChoiceUIGameInstanceSubsystem() { }

	virtual void Initialize();

	virtual void ShowConfirmation();
};
