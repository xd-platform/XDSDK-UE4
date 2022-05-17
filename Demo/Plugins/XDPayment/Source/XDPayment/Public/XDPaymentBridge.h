// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class XDPAYMENT_API XDPaymentBridge
{
public:
     
    //只有iOS有的苹果支付
    virtual void PayWithProduct(FString orderId,
	                            FString productId,
								FString roleId,
								FString serverId,
								FString ext) = 0;

    virtual void QueryWithProductIds(FString listJson) = 0;

	virtual void QueryRestoredPurchases() = 0;

	virtual void CheckRefundStatus() = 0;  //检查是否有补款订单，纯接口

	virtual void CheckRefundStatusWithUI() = 0; //检查是否有补款订单，sdk自带弹框，消失不掉的


    //只有安卓有，iOS没有
	virtual void PayWithWeb(FString orderId,
                        FString productId,
                        FString productName,
                        float  payAmount,
                        FString roleId,
                        FString serverId,
                        FString ext) = 0; //安卓ping++网页支付(微信 支付宝)
	
};

XDPaymentBridge *GetXDPaymentBridge();