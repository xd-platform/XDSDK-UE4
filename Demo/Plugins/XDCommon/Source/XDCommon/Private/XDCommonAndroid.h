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
};

#endif