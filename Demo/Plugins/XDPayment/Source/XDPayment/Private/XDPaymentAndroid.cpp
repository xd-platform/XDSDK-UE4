// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_ANDROID
#include "XDPaymentAndroid.h"
#include "Engine.h"
#include "XDPayment.h"

#define UNREAL4_CLASS_NAME_PAYMENT "com/xd/XDPaymentUnreal4"

XDPaymentAndroid::XDPaymentAndroid()
{
}

XDPaymentAndroid::~XDPaymentAndroid()
{
}

void XDPaymentAndroid::PayWithProduct(FString orderId,
                                        FString productId,
                                        FString roleId,
                                        FString serverId,
                                        FString ext){
    //安卓空
}

void XDPaymentAndroid::QueryWithProductIds(FString listJson){
    //安卓空
}


void XDPaymentAndroid::QueryRestoredPurchases(){
    //安卓空
}


void XDPaymentAndroid::CheckRefundStatus(){
   //安卓空
}


void XDPaymentAndroid::CheckRefundStatusWithUI(){
    //安卓空
}


void XDPaymentAndroid::PayWithWeb(FString orderId,
                    FString productId,
                    FString productName,
                    float  payAmount,
                    FString roleId,
                    FString serverId,
                    FString ext){

    JNIEnv *env = FAndroidApplication::GetJavaEnv();
    auto jXDSDKUnreal4Class = FAndroidApplication::FindJavaClass(UNREAL4_CLASS_NAME_PAYMENT);
    if (jXDSDKUnreal4Class)
    {
        const char *strMethod = "pay";
        auto jMethod = env->GetStaticMethodID(jXDSDKUnreal4Class, strMethod,
                                              "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;F;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
        if (jMethod)
        {
            auto jOrderId = env->NewStringUTF(TCHAR_TO_ANSI(*orderId));
            auto jProductId = env->NewStringUTF(TCHAR_TO_ANSI(*productId));
            auto jProductName = env->NewStringUTF(TCHAR_TO_ANSI(*productName));
            auto jRoleId = env->NewStringUTF(TCHAR_TO_ANSI(*roleId));
            auto jServerId = env->NewStringUTF(TCHAR_TO_ANSI(*serverId));
            auto jExt = env->NewStringUTF(TCHAR_TO_ANSI(*ext));

            env->CallStaticVoidMethod(jXDSDKUnreal4Class, jMethod, jOrderId, jProductId, jProductName, payAmount, jRoleId, jServerId, jExt);

            env->DeleteLocalRef(jOrderId);
            env->DeleteLocalRef(jProductId);
            env->DeleteLocalRef(jProductName);
            env->DeleteLocalRef(jRoleId);
            env->DeleteLocalRef(jServerId);
            env->DeleteLocalRef(jExt);
        }
    }
    env->DeleteLocalRef(jXDSDKUnreal4Class);
}




#ifdef __cplusplus
extern "C"
{
#endif

      __attribute__((visibility("default"))) void Java_com_xd_XDPaymentUnreal4_nativeOnXDSDKPayWithWebCompleted(JNIEnv *jenv, jclass thiz, int32 code ,jstring msg)
    {
          const char *cMsg = jenv->GetStringUTFChars(msg, 0);
        FString fMsg = UTF8_TO_TCHAR(cMsg);
        FXDPaymentModule::OnXDSDKPayWithWebCompleted.Broadcast((int)code, fMsg);
        jenv->ReleaseStringUTFChars(msg, cMsg);
    }


#ifdef __cplusplus
}
#endif


#endif