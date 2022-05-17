// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class XDACCOUNT_API XDAccountBridge
{
public:

    virtual void Login() = 0; //sdk 自带弹框登录

	virtual void LoginByType(FString loginType) = 0; //单点类型登录 Default自动登录，Guest游客登录，TapTap Tap登录

	virtual void Logout() = 0; //退出登录

	virtual void GetUser() = 0; //获取用户

	virtual void OpenUserCenter() = 0;  //打开个人中心

	virtual void AccountCancellation() = 0;  //打开账号注销页面
};

XDAccountBridge *GetXDAccountBridge();
