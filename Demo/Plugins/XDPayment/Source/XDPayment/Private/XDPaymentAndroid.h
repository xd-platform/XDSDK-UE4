// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_ANDROID
#pragma once

#include "CoreMinimal.h"
#include "Core.h"
#include "XDPaymentBridge.h"

#include "Runtime/Launch/Public/Android/AndroidJNI.h"
#include "Runtime/ApplicationCore/Public/Android/AndroidApplication.h"
#include "Runtime/Core/Public/Android/AndroidJava.h"

/**
 * 
 */
class XDPaymentAndroid : public XDPaymentBridge
{
public:
	XDPaymentAndroid();
	~XDPaymentAndroid();


     //只有iOS有的苹果支付
     void PayWithProduct(FString orderId,
	                            FString productId,
								FString roleId,
								FString serverId,
								FString ext);

     void QueryWithProductIds(FString listJson);

	 void QueryRestoredPurchases();

	 void CheckRefundStatus();  //检查是否有补款订单，纯接口

	 void CheckRefundStatusWithUI(); //检查是否有补款订单，sdk自带弹框，消失不掉的

     //只有安卓有，iOS没有
	 void PayWithWeb(FString orderId,
                    FString productId,
                    FString productName,
                    float  payAmount,
                    FString roleId,
                    FString serverId,
                    FString ext); //安卓ping++网页支付(微信 支付宝)

	
};

#endif