// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_IOS
#include "XDCommonIOS.h"
#include "Engine.h"
#include "XDCommon.h"


XDCommonIOS::XDCommonIOS()
{
}

XDCommonIOS::~XDCommonIOS()
{
}

FString XDCommonIOS::GetSDKVersionName(){
    FString version = "";
    NSString * nVersion = [XDSDK getSDKVersionName];
    version = UTF8_TO_TCHAR([nVersion UTF8String]);
    NSLog(@"获取版本号 %@", nVersion);
    return version;
}

bool XDCommonIOS::IsInitialized(){
    bool isInited = false;
    isInited = [XDGGameDataManager isGameInited];
    NSLog(@"是否初始化了 %d", isInited);
    return isInited;
}

void XDCommonIOS::Report(FString serverId, FString roleId, FString roleName){
    [XDSDK reportWithServerId:serverId.GetNSString() roleId:roleId.GetNSString() roleName:roleName.GetNSString()];
    NSLog(@"点击了 Report %@", serverId.GetNSString());
}

void XDCommonIOS::InitSDK(FString clientID, int orientation){
    NSLog(@"开始初始化");

    //绑定统一回调
    [BridgeCallbackHolder sharedInstance:^(NSString * _Nonnull json) {//type, result, errorMsg
        NSLog(@"统一回调结果: %@", json);
        NSData *jsonData = [json dataUsingEncoding:NSUTF8StringEncoding];
        NSError *err = nil;
        NSDictionary *dic = [NSJSONSerialization JSONObjectWithData:jsonData
                                                            options:NSJSONReadingMutableContainers
                                                            error:&err];
        if (err == nil){
            int type = [[NSString stringWithFormat:@"%@", [dic objectForKey:@"type"]] intValue];
            if (type == 0){
                NSString *json = [NSString stringWithFormat:@"%@", [dic objectForKey:@"result"]];
                FXDCommonModule::OnXDSDKLoginCompleted.Broadcast(1, UTF8_TO_TCHAR([json UTF8String])); //登录成功
                
            }else if(type == 1){
                FXDCommonModule::OnXDSDKLoginCompleted.Broadcast(0, "登录失败");

            }else if(type == 2){
                FXDCommonModule::OnXDSDKLoginCompleted.Broadcast(-1, "取消登录");
                
            }else if(type == 3){
                FXDCommonModule::OnXDSDKLogoutSuccess.Broadcast();
                
            }else if(type == 4){
                FXDCommonModule::OnXDSDKSwitchAccount.Broadcast();

            }else if(type == 5){
                FXDCommonModule::OnXDSDKAgreeProtocol.Broadcast();
                
            }else if(type == 6){
                FXDCommonModule::OnXDSDKInitCompleted.Broadcast(true);
                
            }else if(type == 7){
                FXDCommonModule::OnXDSDKInitCompleted.Broadcast(false);
                
            }else if(type == 8){
                FXDCommonModule::OnXDSDKInterruptByRealName.Broadcast();
                
            }else if(type == 9){
                FXDCommonModule::OnXDSDKBindSuccess.Broadcast();
                
            }else if(type == 10){
                FXDCommonModule::OnXDSDKUnBindSuccess.Broadcast();
                
            }
        }else{
            NSLog(@"回调json解析失败: %@", json);
        }
    }];

    XDConfig *config = [XDConfig sharedInstance];
    config.clientID = clientID.GetNSString();
    config.orientation = XDConfigOrientationLandscapeLeft;
    if (orientation == 1) {
        config.orientation = XDConfigOrientationPortrait;
    }
    [XDSDK initSDKConfig:config];
}

void XDCommonIOS::EnterGame(){
    NSLog(@"点击了 EnterGame");
    [XDSDK enterGame];
}

void XDCommonIOS::LeaveGame(){
    NSLog(@"点击了 LeaveGame");
    [XDSDK leaveGame];
}

int XDCommonIOS::GetAntiAddictionAgeRange(){
    int age = [XDSDK getAntiAddictionAgeRange];
    NSLog(@"点击了 GetAntiAddictionAgeRange %d", age);
    return age;
}

#endif