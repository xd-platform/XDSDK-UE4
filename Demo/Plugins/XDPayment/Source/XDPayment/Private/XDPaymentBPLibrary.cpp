// Fill out your copyright notice in the Description page of Project Settings.


#include "XDPaymentBPLibrary.h"
#include "XDPaymentBridge.h"
#include "Engine.h"
#include "TapJson.h"


UXDPaymentBPLibrary::UXDPaymentBPLibrary(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{
}

void UXDPaymentBPLibrary::QueryWithProductIdArray(TArray<FString> productIds){
    FString JsonOutString;
    TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> Writer = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&JsonOutString);
    Writer->WriteObjectStart();
    Writer->WriteValue(TEXT("list"), productIds);
    Writer->WriteObjectEnd();
    Writer->Close();

    GetXDPaymentBridge()->QueryWithProductIds(JsonOutString);    
}

void UXDPaymentBPLibrary::PayWithProduct(FString orderId,
                                        FString productId,
                                        FString roleId,
                                        FString serverId,
                                        FString ext){
    GetXDPaymentBridge()->PayWithProduct(orderId, productId, roleId, serverId, ext);
}


void UXDPaymentBPLibrary::QueryRestoredPurchases(){
    GetXDPaymentBridge()->QueryRestoredPurchases();
}


void UXDPaymentBPLibrary::CheckRefundStatus(){
    GetXDPaymentBridge()->CheckRefundStatus();
}


void UXDPaymentBPLibrary::CheckRefundStatusWithUI(){
    GetXDPaymentBridge()->CheckRefundStatusWithUI();
}

void UXDPaymentBPLibrary::PayWithWeb(FString orderId,
                        FString productId,
                        FString productName,
                        float payAmount,
                        FString roleId,
                        FString serverId,
                        FString ext){
    GetXDPaymentBridge()->PayWithWeb(orderId, productId, productName, payAmount, roleId, serverId, ext);
}