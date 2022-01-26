// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "Engine.h"
#include "TapCommon.h"
#include "TapJson.h"
#include "TapBridge.h"

#include "XDAccountBPLibrary.generated.h"

/**
 * 
 */
UCLASS()
class XDACCOUNT_API UXDAccountBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "XDAccount")
	static void Login();

	UFUNCTION(BlueprintCallable, Category = "XDAccount")
	static void LoginByType(FString loginType);

	UFUNCTION(BlueprintCallable, Category = "XDAccount")
	static void Logout();

	UFUNCTION(BlueprintCallable, Category = "XDAccount")
	static void GetUser();

	UFUNCTION(BlueprintCallable, Category = "XDAccount")
	static void OpenUserCenter(); 
	
};
