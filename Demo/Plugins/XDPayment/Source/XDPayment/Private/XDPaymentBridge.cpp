// Fill out your copyright notice in the Description page of Project Settings.



#include "XDPaymentBridge.h"

#if PLATFORM_ANDROID
#include "XDPaymentAndroid.h"

XDPaymentAndroid * GetXDPaymentAndroidBridge(){
    static XDPaymentAndroid * bridge = nullptr;
    if(bridge == nullptr){
        bridge = new XDPaymentAndroid();
    }
    return bridge;
}

XDPaymentBridge * GetXDPaymentBridge(){
    return GetXDPaymentAndroidBridge();
}

#elif PLATFORM_IOS
#include "XDPaymentIOS.h"

XDPaymentIOS * GetXDPaymentIOSBridge(){
    static XDPaymentIOS * bridge = nullptr;
    if(bridge == nullptr){
        bridge = new XDPaymentIOS();
    }
    return bridge;
}

XDPaymentBridge * GetXDPaymentBridge(){
    return GetXDPaymentIOSBridge();
}

#else

XDPaymentBridge * GetXDPaymentBridge(){
    return nullptr;
}

#endif