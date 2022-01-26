// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include <string.h>
#include "Kismet/BlueprintFunctionLibrary.h"
#include "XDCommonBPLibrary.generated.h"

/**
 * 
 */
UCLASS()
class XDCOMMON_API UXDCommonBPLibrary : public UBlueprintFunctionLibrary
{
	
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, Category = "XDCommon")
	static FString GetSDKVersionName();

	UFUNCTION(BlueprintCallable, Category = "XDCommon")
	static bool IsInitialized();

	UFUNCTION(BlueprintCallable, Category = "XDCommon")
	static void Report(FString serverId, FString roleId, FString roleName);

	UFUNCTION(BlueprintCallable, Category = "XDCommon")
	static void InitSDK(FString clientID, int orientation);

	UFUNCTION(BlueprintCallable, Category = "XDCommon")
	static void EnterGame();

	UFUNCTION(BlueprintCallable, Category = "XDCommon")
	static void LeaveGame();

	UFUNCTION(BlueprintCallable, Category = "XDCommon")
	static int GetAntiAddictionAgeRange();
	
};
