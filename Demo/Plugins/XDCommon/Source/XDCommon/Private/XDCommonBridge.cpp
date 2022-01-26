// Fill out your copyright notice in the Description page of Project Settings.



#include "XDCommonBridge.h"

#if PLATFORM_ANDROID
#include "XDCommonAndroid.h"

XDCommonAndroid * GetXDCommonAndroidBridge(){
    static XDCommonAndroid * bridge = nullptr;
    if(bridge == nullptr){
        bridge = new XDCommonAndroid();
    }
    return bridge;
}

XDCommonBridge * GetXDCommonBridge(){
    return GetXDCommonAndroidBridge();
}

#elif PLATFORM_IOS
#include "XDCommonIOS.h"

XDCommonIOS * GetXDCommonIOSBridge(){
    static XDCommonIOS * bridge = nullptr;
    if(bridge == nullptr){
        bridge = new XDCommonIOS();
    }
    return bridge;
}

XDCommonBridge * GetXDCommonBridge(){
    return GetXDCommonIOSBridge();
}

#else

XDCommonBridge * GetXDCommonBridge(){
    return nullptr;
}

#endif