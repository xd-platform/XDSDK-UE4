// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include <string>
#include "Modules/ModuleManager.h"
#include "CoreUObject.h"
#include "Engine.h"

class FXDPaymentModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static inline FXDPaymentModule& Get(){
        return FModuleManager::LoadModuleChecked<FXDPaymentModule>( "XDPayment" );
    }
    
	static inline bool IsAvailable(){
        return FModuleManager::Get().IsModuleLoaded( "XDPayment" );
    }


	DECLARE_MULTICAST_DELEGATE_FourParams(FXDSDKPaymentSucceed, const FString&, const FString&, const FString&, const FString&);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FXDSDKPaymentFailed, const int32, const FString&);

	DECLARE_MULTICAST_DELEGATE_OneParam(FXDSDKQueryProductIdsSucceed, const FString&);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FXDSDKQueryProductIdsFailed, const int32, const FString&);

	DECLARE_MULTICAST_DELEGATE_OneParam(FXDSDKQueryRestoredPurchasesSucceed, const FString&);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FXDSDKQueryRestoredPurchasesFailed, const int32, const FString&);

	DECLARE_MULTICAST_DELEGATE_OneParam(FXDSDKCheckRefundStatusSucceed, const FString&);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FXDSDKCheckRefundStatusFailed, const int32, const FString&);

    //安卓只有这个，其他都是iOS 
	DECLARE_MULTICAST_DELEGATE_TwoParams(FXDSDKPayWithWebCompleted, const int32, const FString&);

	UPROPERTY(BlueprintAssignable, Category = "XDPayment")
    static FXDSDKPaymentSucceed OnXDSDKPaymentSucceed;

	UPROPERTY(BlueprintAssignable, Category = "XDPayment")
    static FXDSDKPaymentFailed OnXDSDKPaymentFailed;

    //products数组json
	UPROPERTY(BlueprintAssignable, Category = "XDPayment")
    static FXDSDKQueryProductIdsSucceed OnXDSDKQueryProductIdsSucceed;

	UPROPERTY(BlueprintAssignable, Category = "XDPayment")
    static FXDSDKQueryProductIdsFailed OnXDSDKQueryProductIdsFailed;

    //transactions数组json
	UPROPERTY(BlueprintAssignable, Category = "XDPayment")
    static FXDSDKQueryRestoredPurchasesSucceed OnXDSDKQueryRestoredPurchasesSucceed;

	UPROPERTY(BlueprintAssignable, Category = "XDPayment")
    static FXDSDKQueryRestoredPurchasesFailed OnXDSDKQueryRestoredPurchasesFailed;

	UPROPERTY(BlueprintAssignable, Category = "XDPayment")
    static FXDSDKCheckRefundStatusSucceed OnXDSDKCheckRefundStatusSucceed;

	UPROPERTY(BlueprintAssignable, Category = "XDPayment")
    static FXDSDKCheckRefundStatusFailed OnXDSDKCheckRefundStatusFailed;

	//安卓只有这个，其他都是iOS 
	UPROPERTY(BlueprintAssignable, Category = "XDPayment")
    static FXDSDKPayWithWebCompleted OnXDSDKPayWithWebCompleted;
};
