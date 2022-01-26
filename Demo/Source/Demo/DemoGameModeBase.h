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

	
};