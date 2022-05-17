// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include <string.h>
#include "Kismet/BlueprintFunctionLibrary.h"
#include "XDPaymentBPLibrary.generated.h"

/**
 * 
 */
UCLASS()
class XDPAYMENT_API UXDPaymentBPLibrary : public UBlueprintFunctionLibrary
{
	
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, Category = "XDPayment")
	static void QueryWithProductIdArray(TArray<FString> productIds);  

	UFUNCTION(BlueprintCallable, Category = "XDPayment")  //iOS 苹果支付
	static void PayWithProduct(FString orderId,
	                            FString productId,
								FString roleId,
								FString serverId,
								FString ext);

	UFUNCTION(BlueprintCallable, Category = "XDPayment")
	static void QueryRestoredPurchases();

	UFUNCTION(BlueprintCallable, Category = "XDPayment")
	static void CheckRefundStatus();

	UFUNCTION(BlueprintCallable, Category = "XDPayment")
	static void CheckRefundStatusWithUI();

	UFUNCTION(BlueprintCallable, Category = "XDPayment")  //安卓 网页支付
	static void  PayWithWeb(FString orderId,
                        FString productId,
                        FString productName,
                        float payAmount,
                        FString roleId,
                        FString serverId,
                        FString ext);

};
