// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_ANDROID
#pragma once

#include "CoreMinimal.h"
#include "Core.h"
#include "XDCommonBridge.h"

#include "Runtime/Launch/Public/Android/AndroidJNI.h"
#include "Runtime/ApplicationCore/Public/Android/AndroidApplication.h"
#include "Runtime/Core/Public/Android/AndroidJava.h"

/**
 * 
 */
class XDCommonAndroid : public XDCommonBridge
{
public:
	XDCommonAndroid();
	~XDCommonAndroid();

	 FString GetSDKVersionName();

	 bool IsInitialized();

	 void Report(FString serverId, FString roleId, FString roleName);

	 void InitSDK(FString clientID, int orientation);

	 void EnterGame();

	 void LeaveGame();

	 int GetAntiAddictionAgeRange();

	 void TrackUser(FString userId); //登录成功后是要，tap db user统计

	 void TrackRole(FString serverId, FString roleId, FString roleName, int32 level); //角色埋点
	
	 void TrackEvent(FString eventName); //事件埋点

	 void TrackAchievement(); //成就埋点

	 void EventCompletedTutorial(); //完成新手指引埋点

	 void EventCreateRole(); //创建角色埋点
};

#endif