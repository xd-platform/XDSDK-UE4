// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_ANDROID
#include "XDAccountAndroid.h"


#include "Engine.h"
#include "XDAccount.h"

#define UNREAL4_CLASS_NAME_ACCOUNT "com/xd/XDAccountUnreal4"

XDAccountAndroid::XDAccountAndroid()
{
}

XDAccountAndroid::~XDAccountAndroid()
{
}

void XDAccountAndroid::Login(){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_ACCOUNT);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "login";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()V");
        if (jMethod)
        {
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);  
}

void XDAccountAndroid::LoginByType(FString loginType){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_ACCOUNT);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "loginByType";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Ljava/lang/String;)V");
        if (jMethod)
        {
            auto jLoginType = env->NewStringUTF(TCHAR_TO_ANSI(*loginType));

            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, jLoginType);
            env->DeleteLocalRef(jLoginType);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
}

void XDAccountAndroid::Logout(){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_ACCOUNT);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "logout";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()V");
        if (jMethod)
        {
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);  
}

void XDAccountAndroid::GetUser(){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_ACCOUNT);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "getUser";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()V");
        if (jMethod)
        {
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);  
}

void XDAccountAndroid::OpenUserCenter(){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_ACCOUNT);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "openUserCenter";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()V");
        if (jMethod)
        {
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);  
}

void XDAccountAndroid::AccountCancellation(){
    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_ACCOUNT);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "accountCancellation";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "()V");
        if (jMethod)
        {
            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);  
}



#endif