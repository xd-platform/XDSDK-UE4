// Fill out your copyright notice in the Description page of Project Settings.


#include "XDAccountBridge.h"


#if PLATFORM_ANDROID
#include "XDAccountAndroid.h"

XDAccountAndroid * GetXDAccountAndroidBridge(){
    static XDAccountAndroid * bridge = nullptr;
    if(bridge == nullptr){
        bridge = new XDAccountAndroid();
    }
    return bridge;
}

XDAccountBridge * GetXDAccountBridge(){
    return GetXDAccountAndroidBridge();
}

#elif PLATFORM_IOS
#include "XDAccountIOS.h"

XDAccountIOS * GetXDAccountIOSBridge(){
    static XDAccountIOS * bridge = nullptr;
    if(bridge == nullptr){
        bridge = new XDAccountIOS();
    }
    return bridge;
}

XDAccountBridge * GetXDAccountBridge(){
    return GetXDAccountIOSBridge();
}

#else

XDAccountBridge * GetXDAccountBridge(){
    return nullptr;
}

#endif

