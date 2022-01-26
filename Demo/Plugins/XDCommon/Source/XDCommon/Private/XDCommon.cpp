// Copyright Epic Games, Inc. All Rights Reserved.

#include "XDCommon.h"

#define LOCTEXT_NAMESPACE "FXDCommonModule"

void FXDCommonModule::StartupModule(){
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FXDCommonModule::ShutdownModule(){
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}


FXDCommonModule::FXDSDKInitCompleted FXDCommonModule::OnXDSDKInitCompleted;

FXDCommonModule::FXDSDKLoginCompleted FXDCommonModule::OnXDSDKLoginCompleted;

FXDCommonModule::FXDSDKGetUserCompleted FXDCommonModule::OnXDSDKGetUserCompleted;

FXDCommonModule::FXDSDKLogoutSuccess FXDCommonModule::OnXDSDKLogoutSuccess;

FXDCommonModule::FXDSDKSwitchAccount FXDCommonModule::OnXDSDKSwitchAccount;

FXDCommonModule::FXDSDKAgreeProtocol FXDCommonModule::OnXDSDKAgreeProtocol;

FXDCommonModule::FXDSDKInterruptByRealName FXDCommonModule::OnXDSDKInterruptByRealName;

FXDCommonModule::FXDSDKBindSuccess FXDCommonModule::OnXDSDKBindSuccess;

FXDCommonModule::FXDSDKUnBindSuccess FXDCommonModule::OnXDSDKUnBindSuccess;

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FXDCommonModule, XDCommon)