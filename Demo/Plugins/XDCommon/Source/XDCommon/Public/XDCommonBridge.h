// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class XDCOMMON_API XDCommonBridge
{
public:
	
	virtual FString GetSDKVersionName() = 0;

	virtual bool IsInitialized() = 0;

	virtual void Report(FString serverId, FString roleId, FString roleName) = 0;

	virtual void InitSDK(FString clientID, int orientation) = 0;

	virtual void EnterGame() = 0;

	virtual void LeaveGame() = 0;

	virtual int GetAntiAddictionAgeRange() = 0;
};

XDCommonBridge *GetXDCommonBridge();