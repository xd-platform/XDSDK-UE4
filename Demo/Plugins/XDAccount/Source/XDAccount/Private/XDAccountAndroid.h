// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_ANDROID
#pragma once

#include "Core.h"
#include "XDAccountBridge.h"

#include "Runtime/Launch/Public/Android/AndroidJNI.h"
#include "Runtime/ApplicationCore/Public/Android/AndroidApplication.h"
#include "Runtime/Core/Public/Android/AndroidJava.h"

/**
 * 
 */
class XDACCOUNT_API XDAccountAndroid : public XDAccountBridge
{
public:
	XDAccountAndroid();
	~XDAccountAndroid();

	 void Login();

	 void LoginByType(FString loginType);

	 void Logout();

	 void GetUser();

	 void OpenUserCenter();  

};
#endif