// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_IOS
#pragma once

#include "Core.h"
#include "CoreMinimal.h"
#include "XDAccountBridge.h"

#import <Foundation/Foundation.h>
#import <XDAccountSDK/XDAccount.h>
#import <XDCommonSDK/XDUser.h>
#import <XDCommonSDK/XDAccessToken.h>
#import <XDCommonSDK/XDGEntryType.h>
#import <XDAccountSDK/XDLoginService.h>
#import <TDSGlobalSDKCommonKit/NSDictionary+TDSGlobalJson.h>

/**
 * 
 */
class XDACCOUNT_API XDAccountIOS : public XDAccountBridge
{
public:
	XDAccountIOS();
	~XDAccountIOS();

    void Login();

	void LoginByType(FString loginType);

	void Logout();

	void GetUser();

	void OpenUserCenter();  

    void AccountCancellation();  //打开账号注销页面

};
#endif