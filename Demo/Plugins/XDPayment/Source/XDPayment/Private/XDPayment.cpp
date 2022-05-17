// Copyright Epic Games, Inc. All Rights Reserved.

#include "XDPayment.h"
#include "Core.h"

#define LOCTEXT_NAMESPACE "FXDPaymentModule"

void FXDPaymentModule::StartupModule(){}

void FXDPaymentModule::ShutdownModule(){}


FXDPaymentModule::FXDSDKPaymentSucceed FXDPaymentModule::OnXDSDKPaymentSucceed;
FXDPaymentModule::FXDSDKPaymentFailed FXDPaymentModule::OnXDSDKPaymentFailed;

FXDPaymentModule::FXDSDKQueryProductIdsSucceed FXDPaymentModule::OnXDSDKQueryProductIdsSucceed;
FXDPaymentModule::FXDSDKQueryProductIdsFailed FXDPaymentModule::OnXDSDKQueryProductIdsFailed;

FXDPaymentModule::FXDSDKQueryRestoredPurchasesSucceed FXDPaymentModule::OnXDSDKQueryRestoredPurchasesSucceed;
FXDPaymentModule::FXDSDKQueryRestoredPurchasesFailed FXDPaymentModule::OnXDSDKQueryRestoredPurchasesFailed;

FXDPaymentModule::FXDSDKCheckRefundStatusSucceed FXDPaymentModule::OnXDSDKCheckRefundStatusSucceed;
FXDPaymentModule::FXDSDKCheckRefundStatusFailed FXDPaymentModule::OnXDSDKCheckRefundStatusFailed;

FXDPaymentModule::FXDSDKPayWithWebCompleted FXDPaymentModule::OnXDSDKPayWithWebCompleted;


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FXDPaymentModule, XDPayment)
