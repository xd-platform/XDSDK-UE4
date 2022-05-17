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

	UFUNCTION(BlueprintCallable, Category = "XDCommon")
	static void TrackUser(FString userId); //登录成功后是要，tap db user统计

	UFUNCTION(BlueprintCallable, Category = "XDCommon")
	static void TrackRole(FString serverId, FString roleId, FString roleName, int32 level); //角色埋点
	
	UFUNCTION(BlueprintCallable, Category = "XDCommon")	
	static void TrackEvent(FString eventName); //事件埋点

	UFUNCTION(BlueprintCallable, Category = "XDCommon")
	static void TrackAchievement(); //成就埋点

	UFUNCTION(BlueprintCallable, Category = "XDCommon")
	static void EventCompletedTutorial(); //完成新手指引埋点

	UFUNCTION(BlueprintCallable, Category = "XDCommon")
	static void EventCreateRole(); //创建角色埋点
	
};
