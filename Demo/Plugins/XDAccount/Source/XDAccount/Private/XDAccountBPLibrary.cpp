// Fill out your copyright notice in the Description page of Project Settings.


#include "XDAccountBPLibrary.h"
#include "XDAccountBridge.h"


void UXDAccountBPLibrary::Login(){
 GetXDAccountBridge()->Login();
}

void UXDAccountBPLibrary::LoginByType(FString loginType){
 GetXDAccountBridge()->LoginByType(loginType);
}

void UXDAccountBPLibrary::Logout(){
 GetXDAccountBridge()->Logout();

#if PLATFORM_ANDROID || PLATFORM_IOS
    FString commandJson = TapJson::ConstructorCommand(TEXT("TapBootstrapService"),TEXT("logout"),TEXT(""),false,TEXT(""),false);
    GetBridge()->CallHandler(commandJson);
#endif

}

void UXDAccountBPLibrary::GetUser(){
 GetXDAccountBridge()->GetUser();
}

void UXDAccountBPLibrary::OpenUserCenter(){
 GetXDAccountBridge()->OpenUserCenter();
}