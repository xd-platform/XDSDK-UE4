// Copyright Epic Games, Inc. All Rights Reserved.


#include "DemoGameModeBase.h"
#include "XDCommon.h"
#include "XDAccount.h"
#include <string.h>


void ADemoGameModeBase::BeginPlay(){
    
    FXDCommonModule::OnXDSDKInitCompleted.AddUObject(this, &ADemoGameModeBase::OnXDSDKInitCompleted);

    FXDCommonModule::OnXDSDKLoginCompleted.AddUObject(this, &ADemoGameModeBase::OnXDSDKLoginCompleted);

    FXDCommonModule::OnXDSDKGetUserCompleted.AddUObject(this, &ADemoGameModeBase::OnXDSDKGetUserCompleted);

    FXDCommonModule::OnXDSDKLogoutSuccess.AddUObject(this, &ADemoGameModeBase::OnXDSDKLogoutSuccess);

    FXDCommonModule::OnXDSDKSwitchAccount.AddUObject(this, &ADemoGameModeBase::OnXDSDKSwitchAccount);

    FXDCommonModule::OnXDSDKAgreeProtocol.AddUObject(this, &ADemoGameModeBase::OnXDSDKAgreeProtocol);

    FXDCommonModule::OnXDSDKInterruptByRealName.AddUObject(this, &ADemoGameModeBase::OnXDSDKInterruptByRealName);

    FXDCommonModule::OnXDSDKBindSuccess.AddUObject(this, &ADemoGameModeBase::OnXDSDKBindSuccess);

    FXDCommonModule::OnXDSDKUnBindSuccess.AddUObject(this, &ADemoGameModeBase::OnXDSDKUnBindSuccess);

    UE_LOG(LogTemp, Log, TEXT("开始 DemoGameModeBase BeginPlay"));
}


void ADemoGameModeBase::OnXDSDKInitCompleted(const bool success){
    GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red,  FString::FromInt(success));
}

void ADemoGameModeBase::OnXDSDKLoginCompleted(const int32 code, const FString& result){
   if (code == 1){
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Success");
   }else if(code == 0){
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Fail");
   }else{
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Cancel");
   }
}

void ADemoGameModeBase::OnXDSDKGetUserCompleted(const int32 code, const FString& result){
     if (code == 1){
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Success");
   }else{
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Fail");
   }
}

void ADemoGameModeBase::OnXDSDKLogoutSuccess(){
    GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Success");
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


