// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_IOS
#pragma once

#include "CoreMinimal.h"
#include "XDPaymentBridge.h"

#import <Foundation/Foundation.h>
#import <XDPaymentSDK/XDTransactionInfo.h>
#import <XDPaymentSDK/XDPayment.h>
#import <XDPaymentSDK/XDProductInfo.h>
#import <TDSGlobalSDKCommonKit/NSDictionary+TDSGlobalJson.h>
#import <XDPaymentSDK/XDOrderInfo.h>


/**
 * 
 */
class XDPayment_API XDPaymentIOS : public XDPaymentBridge
{
public:
	 XDPaymentIOS();
	 ~XDPaymentIOS();

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

@interface XDUE4PaymentTool : NSObject

+(NSArray*)getProductIdList:(NSString*)listJson;

+ (void)bridgePayCallback:(XDOrderInfo *)orderInfo error:(NSError *)error;

+ (void)bridgeRefundStatusWithCode:(XDGRepayMentCode)code msg:(NSString *)msg data:(NSDictionary *)data;

+ (NSString *)randomStr;

@end

#endif