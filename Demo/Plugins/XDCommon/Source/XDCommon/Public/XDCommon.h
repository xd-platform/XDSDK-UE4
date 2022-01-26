// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class XDCOMMON_API FXDCommonModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static inline FXDCommonModule& Get(){
        return FModuleManager::LoadModuleChecked<FXDCommonModule>( "XDCommon" );
    }
    
	static inline bool IsAvailable(){
        return FModuleManager::Get().IsModuleLoaded( "XDCommon" );
    }

    
	DECLARE_MULTICAST_DELEGATE_OneParam(FXDSDKInitCompleted, const bool);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FXDSDKLoginCompleted, const int32, const FString&);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FXDSDKGetUserCompleted, const int32, const FString&);
	DECLARE_MULTICAST_DELEGATE(FXDSDKLogoutSuccess);
	DECLARE_MULTICAST_DELEGATE(FXDSDKSwitchAccount);
	DECLARE_MULTICAST_DELEGATE(FXDSDKAgreeProtocol);
	DECLARE_MULTICAST_DELEGATE(FXDSDKInterruptByRealName);
	DECLARE_MULTICAST_DELEGATE(FXDSDKBindSuccess);
	DECLARE_MULTICAST_DELEGATE(FXDSDKUnBindSuccess);

	UPROPERTY(BlueprintAssignable, Category = "XDCommon")
    static FXDSDKInitCompleted OnXDSDKInitCompleted;

	UPROPERTY(BlueprintAssignable, Category = "XDCommon")
    static FXDSDKLoginCompleted OnXDSDKLoginCompleted;

	UPROPERTY(BlueprintAssignable, Category = "XDCommon")
    static FXDSDKGetUserCompleted OnXDSDKGetUserCompleted;

	UPROPERTY(BlueprintAssignable, Category = "XDCommon")
    static FXDSDKLogoutSuccess OnXDSDKLogoutSuccess;

	UPROPERTY(BlueprintAssignable, Category = "XDCommon")
    static FXDSDKSwitchAccount OnXDSDKSwitchAccount;

	UPROPERTY(BlueprintAssignable, Category = "XDCommon")
    static FXDSDKAgreeProtocol OnXDSDKAgreeProtocol;

	UPROPERTY(BlueprintAssignable, Category = "XDCommon")
    static FXDSDKInterruptByRealName OnXDSDKInterruptByRealName;

	UPROPERTY(BlueprintAssignable, Category = "XDCommon")
    static FXDSDKBindSuccess OnXDSDKBindSuccess;

	UPROPERTY(BlueprintAssignable, Category = "XDCommon")
    static FXDSDKUnBindSuccess OnXDSDKUnBindSuccess;	
};
