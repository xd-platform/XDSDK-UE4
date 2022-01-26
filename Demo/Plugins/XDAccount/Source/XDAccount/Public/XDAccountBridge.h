// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class XDACCOUNT_API XDAccountBridge
{
public:

    virtual void Login() = 0;

	virtual void LoginByType(FString loginType) = 0;

	virtual void Logout() = 0;

	virtual void GetUser() = 0;

	virtual void OpenUserCenter() = 0; 
};

XDAccountBridge *GetXDAccountBridge();
