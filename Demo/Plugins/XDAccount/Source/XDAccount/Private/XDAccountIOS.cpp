// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_IOS
#include "XDAccountIOS.h"
#include "Engine.h"
#include "XDCommon.h"


XDAccountIOS::XDAccountIOS()
{
}

XDAccountIOS::~XDAccountIOS()
{
}


void XDAccountIOS::Login(){
     dispatch_async(dispatch_get_main_queue(), ^{
        [XDAccount loginWithPolicy];
    });
}

void XDAccountIOS::LoginByType(FString loginType){
     dispatch_async(dispatch_get_main_queue(), ^{
         LoginEntryType type = LoginEntryTypeDefault;

         NSString* str = loginType.GetNSString();
         if ([@"taptap" isEqualToString:[str lowercaseString]]){
            type = LoginEntryTypeTapTap;
         }
         
        [XDAccount loginWithPolicyByType:type];
    });
}

void XDAccountIOS::Logout(){
     dispatch_async(dispatch_get_main_queue(), ^{
        [XDAccount logout];
        NSLog(@"点击退出登录");
    });
}

void XDAccountIOS::GetUser(){
    [XDAccount getUser:^(XDUser * _Nullable result, NSError * _Nullable error) {
       NSString* userJson = [XDLoginService bridgeUserCallback:result error:error];
       NSLog(@"获取用户信息: %@", userJson);

       if(result != nil){
          FXDCommonModule::OnXDSDKGetUserCompleted.Broadcast(1, UTF8_TO_TCHAR([userJson UTF8String]));
       }else{
          FXDCommonModule::OnXDSDKGetUserCompleted.Broadcast(0, "获取用户信息失败");
          NSLog(@"获取用户信息是空");
       }
    }];
}

void XDAccountIOS::OpenUserCenter(){
      dispatch_async(dispatch_get_main_queue(), ^{
       [XDAccount openUserCenter];
    });
}

#endif