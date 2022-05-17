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

	virtual void Report(FString serverId, FString roleId, FString roleName) = 0; //打开客服反馈

	virtual void InitSDK(FString clientID, int orientation) = 0; //初始化，成功后才可以调用登录

	virtual void EnterGame() = 0;  //登录成功，游戏进入前台调用

	virtual void LeaveGame() = 0;  //退出登录，游戏进入后台调用

	virtual int GetAntiAddictionAgeRange() = 0; //获取防沉迷年龄段

	virtual void TrackUser(FString userId) = 0; //登录成功后是要，tap db user统计

	virtual void TrackRole(FString serverId, FString roleId, FString roleName, int32 level) = 0; //角色埋点
	
	virtual void TrackEvent(FString eventName) = 0; //事件埋点

	virtual void TrackAchievement() = 0; //成就埋点

	virtual void EventCompletedTutorial() = 0; //完成新手指引埋点

	virtual void EventCreateRole() = 0; //创建角色埋点
	
};

XDCommonBridge *GetXDCommonBridge();