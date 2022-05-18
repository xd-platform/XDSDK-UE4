// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_ANDROID
#include "XDCommonAndroid.h"
#include "Engine.h"
#include "XDCommon.h"

#define UNREAL4_CLASS_NAME_COMMON "com/xd/XDCommonUnreal4"

XDCommonAndroid::XDCommonAndroid()
{
}

XDCommonAndroid::~XDCommonAndroid()
{
}


FString XDCommonAndroid::GetSDKVersionName(){
    FString version = "";
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "getSDKVersionName";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()Ljava/lang/String;");
        if (jMethod)
        {
            auto jVersion = (jstring)(env->CallStaticObjectMethod(jXDSDKUnreal4Class, jMethod));
            const char *versionChar = env->GetStringUTFChars(jVersion, 0);
            version = ANSI_TO_TCHAR(versionChar);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
    return version;
}

bool XDCommonAndroid::IsInitialized(){
    bool isEnable = false;
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "isInitialized";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()Z");
        if (jMethod)
        {
            isEnable = (bool)(env->CallStaticBooleanMethod(jXDSDKUnreal4Class, jMethod));
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
    return isEnable;
}

void XDCommonAndroid::Report(FString serverId, FString roleId, FString roleName){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "report";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
        if (jMethod)
        {
            auto jServerId = env->NewStringUTF(TCHAR_TO_ANSI(*serverId));
            auto jRoleId = env->NewStringUTF(TCHAR_TO_ANSI(*roleId));
            auto jRoleName = env->NewStringUTF(TCHAR_TO_ANSI(*roleName));

            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, jServerId, jRoleId, jRoleName);
            env->DeleteLocalRef(jServerId);
            env->DeleteLocalRef(jRoleId);
            env->DeleteLocalRef(jRoleName);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
}

void XDCommonAndroid::InitSDK(FString clientID, int orientation){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "initSDK";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Landroid/app/Activity;Ljava/lang/String;I)V");
        if (jMethod)
        {
            auto jActivity = FAndroidApplication::GetGameActivityThis();
            auto jClientID = env->NewStringUTF(TCHAR_TO_ANSI(*clientID));

            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, jActivity, jClientID, orientation);
            env->DeleteLocalRef(jClientID);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
}


void XDCommonAndroid::EnterGame(){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "enterGame";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()V");
        if (jMethod)
        {
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);   
}

void XDCommonAndroid::LeaveGame(){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "leaveGame";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()V");
        if (jMethod)
        {
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);   
}


// -1	未实名
// 0	0 到 7 岁
// 8	8 到 15 岁
// 16	16 到 17 岁
// 18	成年玩家
int XDCommonAndroid::GetAntiAddictionAgeRange(){
    int num = -1;
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "getAntiAddictionAgeRange";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()I");
        if (jMethod)
        {
           num = (int)(env->CallStaticIntMethod(jXDSDKUnreal4Class, jMethod));
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);   
    return num;
}

void XDCommonAndroid::TrackUser(FString userId){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "trackUser";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Ljava/lang/String;)V");
        if (jMethod)
        {
            auto jUserId = env->NewStringUTF(TCHAR_TO_ANSI(*userId));

            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, jUserId);
            env->DeleteLocalRef(jUserId);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
    
}

void XDCommonAndroid::TrackRole(FString serverId, FString roleId, FString roleName, int32 level){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "trackRole";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V");
        if (jMethod)
        {
            auto jServerId = env->NewStringUTF(TCHAR_TO_ANSI(*serverId));
            auto jRoleId = env->NewStringUTF(TCHAR_TO_ANSI(*roleId));
            auto jRoleName = env->NewStringUTF(TCHAR_TO_ANSI(*roleName));

            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod,jServerId,jRoleId,jRoleName,level);

            env->DeleteLocalRef(jServerId);
            env->DeleteLocalRef(jRoleId);
            env->DeleteLocalRef(jRoleName);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);   
}
	
void XDCommonAndroid::TrackEvent(FString eventName){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "trackEvent";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Ljava/lang/String;)V");
        if (jMethod)
        {
            auto jEventName = env->NewStringUTF(TCHAR_TO_ANSI(*eventName));

            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, jEventName);

             env->DeleteLocalRef(jEventName);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);  
}

void XDCommonAndroid::TrackAchievement(){
      JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "trackAchievement";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()V");
        if (jMethod)
        {
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);      
}

void XDCommonAndroid::EventCompletedTutorial(){
     JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "eventCompletedTutorial";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()V");
        if (jMethod)
        {
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);   
}

void XDCommonAndroid::EventCreateRole(){
     JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "eventCreateRole";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()V");
        if (jMethod)
        {
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);   
} 

void XDCommonAndroid::DevelopUrlInit(){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_COMMON);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "developUrlInit";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Landroid/app/Activity;)V");
        if (jMethod)
        {
            auto jActivity = FAndroidApplication::GetGameActivityThis();
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, jActivity);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class); 
} 





#ifdef __cplusplus
extern "C"
{
#endif

  __attribute__((visibility("default"))) void Java_com_xd_XDCommonUnreal4_nativeOnXDSDKInitCompleted(JNIEnv *jenv, jclass thiz, jboolean success)
    {
        FXDCommonModule::OnXDSDKInitCompleted.Broadcast((bool)success);
    }

     __attribute__((visibility("default"))) void Java_com_xd_XDCommonUnreal4_nativeOnXDSDKLoginCompleted(JNIEnv *jenv, jclass thiz, int32 code ,jstring userJson)
    {
        const char *cUserJson = jenv->GetStringUTFChars(userJson, 0);
        FString fUserJson = UTF8_TO_TCHAR(cUserJson);
        FXDCommonModule::OnXDSDKLoginCompleted.Broadcast((int)code, fUserJson);
        jenv->ReleaseStringUTFChars(userJson, cUserJson);
    }

      __attribute__((visibility("default"))) void Java_com_xd_XDCommonUnreal4_nativeOnXDSDKGetUserCompleted(JNIEnv *jenv, jclass thiz, int32 code ,jstring userJson)
    {
        const char *cUserJson = jenv->GetStringUTFChars(userJson, 0);
        FString fUserJson = UTF8_TO_TCHAR(cUserJson);
        FXDCommonModule::OnXDSDKGetUserCompleted.Broadcast((int)code, fUserJson);
        jenv->ReleaseStringUTFChars(userJson, cUserJson);
    }

       __attribute__((visibility("default"))) void Java_com_xd_XDCommonUnreal4_nativeOnXDSDKLogoutSuccess(JNIEnv *jenv, jclass thiz)
    {
        FXDCommonModule::OnXDSDKLogoutSuccess.Broadcast();
    }

       __attribute__((visibility("default"))) void Java_com_xd_XDCommonUnreal4_nativeOnXDSDKSwitchAccount(JNIEnv *jenv, jclass thiz)
    {
        FXDCommonModule::OnXDSDKSwitchAccount.Broadcast();
    }

       __attribute__((visibility("default"))) void Java_com_xd_XDCommonUnreal4_nativeOnXDSDKAgreeProtocol(JNIEnv *jenv, jclass thiz)
    {
        FXDCommonModule::OnXDSDKAgreeProtocol.Broadcast();
    }

        __attribute__((visibility("default"))) void Java_com_xd_XDCommonUnreal4_nativeOnXDSDKInterruptByRealName(JNIEnv *jenv, jclass thiz)
    {
        FXDCommonModule::OnXDSDKInterruptByRealName.Broadcast();
    }

         __attribute__((visibility("default"))) void Java_com_xd_XDCommonUnreal4_nativeOnXDSDKBindSuccess(JNIEnv *jenv, jclass thiz)
    {
        FXDCommonModule::OnXDSDKBindSuccess.Broadcast();
    }

         __attribute__((visibility("default"))) void Java_com_xd_XDCommonUnreal4_nativeOnXDSDKUnBindSuccess(JNIEnv *jenv, jclass thiz)
    {
        FXDCommonModule::OnXDSDKUnBindSuccess.Broadcast();
    }

#ifdef __cplusplus
}
#endif


#endif