// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DemoGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DEMO_API ADemoGameModeBase : public AGameModeBase
{

	GENERATED_BODY()

	//Common
	virtual void BeginPlay() override;

	void OnXDSDKInitCompleted(const bool);

	void OnXDSDKLoginCompleted(const int32, const FString&);

	void OnXDSDKGetUserCompleted(const int32, const FString&);

	void OnXDSDKLogoutSuccess();

	void OnXDSDKSwitchAccount();

	void OnXDSDKAgreeProtocol();

	void OnXDSDKInterruptByRealName();

	void OnXDSDKBindSuccess();

	void OnXDSDKUnBindSuccess();

	//Payment 
    void OnXDSDKPaymentSucceed(const FString&, const FString&, const FString&, const FString&);

    void OnXDSDKPaymentFailed(const int32, const FString&);

    void OnXDSDKQueryProductIdsSucceed(const FString&);

    void OnXDSDKQueryProductIdsFailed(const int32, const FString&);

    void OnXDSDKQueryRestoredPurchasesSucceed(const FString&);

    void OnXDSDKQueryRestoredPurchasesFailed(const int32, const FString&);

    void OnXDSDKCheckRefundStatusSucceed(const FString&);

    void OnXDSDKCheckRefundStatusFailed(const int32, const FString&);

    void OnXDSDKPayWithWebCompleted(const int32, const FString&);

};