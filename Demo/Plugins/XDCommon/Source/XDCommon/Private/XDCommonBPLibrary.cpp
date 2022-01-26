// Fill out your copyright notice in the Description page of Project Settings.


#include "XDCommonBPLibrary.h"
#include "XDCommonBridge.h"
#include "Engine.h"


UXDCommonBPLibrary::UXDCommonBPLibrary(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{
}

FString UXDCommonBPLibrary::GetSDKVersionName(){
    FString value = GetXDCommonBridge()->GetSDKVersionName();
    GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red,  value); //发布注销
    return value;
}

bool UXDCommonBPLibrary::IsInitialized(){
    bool value = GetXDCommonBridge()->IsInitialized();
    GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red,  FString::FromInt(value)); //发布注销
    return value;
}

void UXDCommonBPLibrary::Report(FString serverId, FString roleId, FString roleName){
    GetXDCommonBridge()->Report(serverId, roleId, roleName);
}

void UXDCommonBPLibrary::InitSDK(FString clientID, int orientation){
    GetXDCommonBridge()->InitSDK(clientID, orientation);
}

void UXDCommonBPLibrary::EnterGame(){
    GetXDCommonBridge()->EnterGame();
}

void UXDCommonBPLibrary::LeaveGame(){
    GetXDCommonBridge()->LeaveGame();
}

int UXDCommonBPLibrary::GetAntiAddictionAgeRange(){
    int value = GetXDCommonBridge()->GetAntiAddictionAgeRange();
    GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red,  FString::FromInt(value)); //发布注销
    return value;
}
