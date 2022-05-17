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

	UFUNCTION(BlueprintCallable, Category = "XDAccount")//sdk 自带弹框登录
	static void Login();

	UFUNCTION(BlueprintCallable, Category = "XDAccount")//单点类型登录，国内只有三种类型： Default自动登录，Guest游客登录，TapTap Tap登录
	static void LoginByType(FString loginType);

	UFUNCTION(BlueprintCallable, Category = "XDAccount")//退出登录
	static void Logout();

	UFUNCTION(BlueprintCallable, Category = "XDAccount")//获取用户
	static void GetUser();

	UFUNCTION(BlueprintCallable, Category = "XDAccount")//打开个人中心
	static void OpenUserCenter(); 

	UFUNCTION(BlueprintCallable, Category = "XDAccount") //打开账号注销页面
	static void AccountCancellation(); 
	
};
