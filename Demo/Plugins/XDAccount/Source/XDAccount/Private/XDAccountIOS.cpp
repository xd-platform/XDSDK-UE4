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

void XDAccountIOS::LoginByType(FString loginType){ //国内目前只有 Default , Guest, TapTap
     dispatch_async(dispatch_get_main_queue(), ^{
         LoginEntryType type = LoginEntryTypeDefault;

         NSString* str = loginType.GetNSString();
         if ([@"taptap" isEqualToString:[str lowercaseString]]){
            type = LoginEntryTypeTapTap;

         }else  if ([@"guest" isEqualToString:[str lowercaseString]]){
            type = LoginEntryTypeGuest;
         }
         NSLog(@"单点登录类型: %@", str);
         
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
            NSData* resultData = [userJson dataUsingEncoding:NSUTF8StringEncoding];
            NSDictionary* resultDic = [NSJSONSerialization JSONObjectWithData:resultData
                                                                    options:NSJSONReadingMutableContainers
                                                                    error:nil];
            NSDictionary* userDic = [resultDic objectForKey:@"user"];
            FXDCommonModule::OnXDSDKGetUserCompleted.Broadcast(1, UTF8_TO_TCHAR([userDic.tdsglobal_jsonString UTF8String])); 
       }else{
          FXDCommonModule::OnXDSDKGetUserCompleted.Broadcast(0, TEXT("获取用户信息失败"));
          NSLog(@"获取用户信息: 是空");
       }
    }];
}

void XDAccountIOS::OpenUserCenter(){
      dispatch_async(dispatch_get_main_queue(), ^{
       [XDAccount openUserCenter];
        NSLog(@"点击打开个人中心");
    });
}

void XDAccountIOS::AccountCancellation(){
      dispatch_async(dispatch_get_main_queue(), ^{
       [XDAccount accountCancellation];
        NSLog(@"点击打开账号注销");
    });
}

#endif