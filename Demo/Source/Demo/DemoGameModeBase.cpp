// Copyright Epic Games, Inc. All Rights Reserved.


#include "DemoGameModeBase.h"
#include "XDCommon.h"
#include "XDAccount.h"
#include "XDPayment.h"
#include <string.h>


void ADemoGameModeBase::BeginPlay(){
    
    //Common
    FXDCommonModule::OnXDSDKInitCompleted.AddUObject(this, &ADemoGameModeBase::OnXDSDKInitCompleted);

    FXDCommonModule::OnXDSDKLoginCompleted.AddUObject(this, &ADemoGameModeBase::OnXDSDKLoginCompleted);

    FXDCommonModule::OnXDSDKGetUserCompleted.AddUObject(this, &ADemoGameModeBase::OnXDSDKGetUserCompleted);

    FXDCommonModule::OnXDSDKLogoutSuccess.AddUObject(this, &ADemoGameModeBase::OnXDSDKLogoutSuccess);

    FXDCommonModule::OnXDSDKSwitchAccount.AddUObject(this, &ADemoGameModeBase::OnXDSDKSwitchAccount);

    FXDCommonModule::OnXDSDKAgreeProtocol.AddUObject(this, &ADemoGameModeBase::OnXDSDKAgreeProtocol);

    FXDCommonModule::OnXDSDKInterruptByRealName.AddUObject(this, &ADemoGameModeBase::OnXDSDKInterruptByRealName);

    FXDCommonModule::OnXDSDKBindSuccess.AddUObject(this, &ADemoGameModeBase::OnXDSDKBindSuccess);

    FXDCommonModule::OnXDSDKUnBindSuccess.AddUObject(this, &ADemoGameModeBase::OnXDSDKUnBindSuccess);
    
    // //Payment
    FXDPaymentModule::OnXDSDKPaymentSucceed.AddUObject(this, &ADemoGameModeBase::OnXDSDKPaymentSucceed);

    FXDPaymentModule::OnXDSDKPaymentFailed.AddUObject(this, &ADemoGameModeBase::OnXDSDKPaymentFailed);

    FXDPaymentModule::OnXDSDKQueryProductIdsSucceed.AddUObject(this, &ADemoGameModeBase::OnXDSDKQueryProductIdsSucceed);

    FXDPaymentModule::OnXDSDKQueryProductIdsFailed.AddUObject(this, &ADemoGameModeBase::OnXDSDKQueryProductIdsFailed);

    FXDPaymentModule::OnXDSDKQueryRestoredPurchasesSucceed.AddUObject(this, &ADemoGameModeBase::OnXDSDKQueryRestoredPurchasesSucceed);

    FXDPaymentModule::OnXDSDKQueryRestoredPurchasesFailed.AddUObject(this, &ADemoGameModeBase::OnXDSDKQueryRestoredPurchasesFailed);

    FXDPaymentModule::OnXDSDKCheckRefundStatusSucceed.AddUObject(this, &ADemoGameModeBase::OnXDSDKCheckRefundStatusSucceed);

    FXDPaymentModule::OnXDSDKCheckRefundStatusFailed.AddUObject(this, &ADemoGameModeBase::OnXDSDKCheckRefundStatusFailed);

    FXDPaymentModule::OnXDSDKPayWithWebCompleted.AddUObject(this, &ADemoGameModeBase::OnXDSDKPayWithWebCompleted);


    UE_LOG(LogTemp, Log, TEXT("开始 DemoGameModeBase BeginPlay"));
}


//Common
void ADemoGameModeBase::OnXDSDKInitCompleted(const bool success){
    GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red,  "Init Result: " + FString::FromInt(success));
}

void ADemoGameModeBase::OnXDSDKLoginCompleted(const int32 code, const FString& result){
   if (code == 1){
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Success: " + result);
   }else if(code == 0){
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Fail: " + result);
   }else{
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Cancel: " + result);
   }
}

void ADemoGameModeBase::OnXDSDKGetUserCompleted(const int32 code, const FString& result){
     if (code == 1){
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Success: " + result);
   }else{
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Fail");
   }
}

void ADemoGameModeBase::OnXDSDKLogoutSuccess(){
    GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Logout Success");
}

void ADemoGameModeBase::OnXDSDKSwitchAccount(){
    GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Switch Success");
}

void ADemoGameModeBase::OnXDSDKAgreeProtocol(){
    GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Agree Success");
}

void ADemoGameModeBase::OnXDSDKInterruptByRealName(){
    GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "To RealName");
}

void ADemoGameModeBase::OnXDSDKBindSuccess(){
    GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Bind Success");
}

void ADemoGameModeBase::OnXDSDKUnBindSuccess(){
    GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "UnBind Success");
}


//Payment
void ADemoGameModeBase::OnXDSDKPaymentSucceed(const FString& orderId, const FString& productId, const FString& serverId, const FString& roleId){
    GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Pay Success, orderId: " + orderId + "productId: " + productId);
}

void ADemoGameModeBase::OnXDSDKPaymentFailed(const int32 code, const FString& msg){
    GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Pay Fail, code: " + FString::FromInt(code) + " msg: " + msg);
}

void ADemoGameModeBase::OnXDSDKQueryProductIdsSucceed(const FString& resultJson){
    GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Success: " + resultJson);
}

void ADemoGameModeBase::OnXDSDKQueryProductIdsFailed(const int32 code, const FString& msg){
   GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Fail code: " + FString::FromInt(code) + " msg: " + msg);
}

void ADemoGameModeBase::OnXDSDKQueryRestoredPurchasesSucceed(const FString& resultJson){
    GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Success: " + resultJson);
}

void ADemoGameModeBase::OnXDSDKQueryRestoredPurchasesFailed(const int32 code, const FString& msg){
  GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Fail code: " + FString::FromInt(code) + " msg: " + msg);
}

void ADemoGameModeBase::OnXDSDKCheckRefundStatusSucceed(const FString& resultJson){
      GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Success: " + resultJson);
}

void ADemoGameModeBase::OnXDSDKCheckRefundStatusFailed(const int32 code, const FString& msg){
   GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Fail code: " + FString::FromInt(code) + " msg: " + msg);
}

void ADemoGameModeBase::OnXDSDKPayWithWebCompleted(const int32 code, const FString& msg){
   GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Fail code: " + FString::FromInt(code) + " msg: " + msg);
}
