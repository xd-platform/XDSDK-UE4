// Fill out your copyright notice in the Description page of Project Settings.


#include "XDCommonBPLibrary.h"
#include "XDCommonBridge.h"
#include "Engine.h"

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"


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

 void UXDCommonBPLibrary::TrackUser(FString userId){
    GetXDCommonBridge()->TrackUser(userId);
 }

 void UXDCommonBPLibrary::TrackRole(FString serverId, FString roleId, FString roleName, int32 level){
      GetXDCommonBridge()->TrackRole(serverId, roleId, roleName, level);
 }
	
 void UXDCommonBPLibrary::TrackEvent(FString eventName){
      GetXDCommonBridge()->TrackEvent(eventName);
 }

 void UXDCommonBPLibrary::TrackAchievement(){
      GetXDCommonBridge()->TrackAchievement();
 }

 void UXDCommonBPLibrary::EventCompletedTutorial(){
      GetXDCommonBridge()->EventCompletedTutorial();
 }

 void UXDCommonBPLibrary::EventCreateRole(){
      GetXDCommonBridge()->EventCreateRole();
 }

 void UXDCommonBPLibrary::DevelopUrlInit(){
      GetXDCommonBridge()->DevelopUrlInit();
 }


 void UXDCommonBPLibrary::ShowTest(){
    //测试代码
    //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green,  TEXT("InitSucceed3 中文 ศูนย์ความปลอดภัยบัญชี"), true, FVector2D(2, 2));
    //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "OnSDKInitSucceed 中文 ศูนย์ความปลอดภัยบัญชี");
}