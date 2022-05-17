// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_IOS
#include "XDPaymentIOS.h"
#include "Engine.h"
#include "XDPayment.h"


XDPaymentIOS::XDPaymentIOS()
{
}

XDPaymentIOS::~XDPaymentIOS()
{
}

void XDPaymentIOS::QueryWithProductIds(FString listJson){
    NSArray* productIds = [XDUE4PaymentTool getProductIdList: listJson.GetNSString()];

    [XDPayment queryWithProductIds:productIds completionHandler:^(NSArray<XDProductInfo *> * _Nullable result, NSError * _Nullable error) {
        NSMutableDictionary *resultDic = [NSMutableDictionary dictionary];
        __block NSMutableArray *products = [NSMutableArray array];

        [result enumerateObjectsUsingBlock:^(XDProductInfo * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            NSDictionary *productInfo = @{
                @"localizedDescription":obj.localizedDescription?:@"",
                @"localizedTitle":obj.localizedTitle?:@"",
                @"price":obj.price,
                @"productIdentifier":obj.productIdentifier?:@"",
                @"priceLocale":@{
                        @"localeIdentifier":obj.priceLocale.localeIdentifier?:@"",
                        @"languageCode":obj.priceLocale.languageCode?:@"",
                        @"countryCode":obj.priceLocale.countryCode?:@"",
                        @"scriptCode":obj.priceLocale.scriptCode?:@"",
                        @"calendarIdentifier":obj.priceLocale.calendarIdentifier?:@"",
                        @"decimalSeparator":obj.priceLocale.decimalSeparator?:@"",
                        @"currencySymbol":obj.priceLocale.currencySymbol?:@"",
                }
            };
            [products addObject:productInfo];
        }];
        
        if (error != nil) {
            FXDPaymentModule::OnXDSDKQueryProductIdsFailed.Broadcast((int)error.code, UTF8_TO_TCHAR([error.localizedDescription?:@"" UTF8String]));
            NSLog(@"QueryWithProductIds查询失败: %@",error.localizedDescription?:@"");
        }else{
            [resultDic setObject:products forKey:@"products"];
            NSString* json = resultDic.tdsglobal_jsonString;
            FXDPaymentModule::OnXDSDKQueryProductIdsSucceed.Broadcast(UTF8_TO_TCHAR([json UTF8String]));
            NSLog(@"QueryWithProductIds查询成功: %@", json);
        }
    }];
}

void XDPaymentIOS::PayWithProduct(FString orderId,
                            FString productId,
                            FString roleId,
                            FString serverId,
                            FString ext){
    dispatch_async(dispatch_get_main_queue(), ^{                     
        [XDPayment payWithOrderId:orderId.GetNSString() productId:productId.GetNSString() roleId:roleId.GetNSString() serverId:serverId.GetNSString() ext:ext.GetNSString() completionHandler:^(XDOrderInfo * _Nonnull orderInfo, NSError * _Nonnull error) {
            [XDUE4PaymentTool bridgePayCallback:orderInfo error:error];
        }];   
     });                            
}


void XDPaymentIOS::QueryRestoredPurchases(){
    [XDPayment queryRestoredPurchases:^(NSArray<XDTransactionInfo *> * _Nonnull result) {
        if (result != nil){
             __block NSMutableArray *transactions = [NSMutableArray array];
            [result enumerateObjectsUsingBlock:^(XDTransactionInfo * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                NSDictionary *transactionInfo = @{
                    @"transactionIdentifier":obj.transactionIdentifier?:@"",
                    @"productIdentifier":obj.productIdentifier?:@"",
                };
                [transactions addObject:transactionInfo];
            }];
            
            NSDictionary *resultDic = @{
                @"transactions":transactions
            };
            NSString* strJson = resultDic.tdsglobal_jsonString;
            FXDPaymentModule::OnXDSDKQueryRestoredPurchasesSucceed.Broadcast(UTF8_TO_TCHAR([strJson UTF8String]));
            NSLog(@"QueryRestoredPurchases查询成功 %@", strJson);

        }else{
            FXDPaymentModule::OnXDSDKQueryRestoredPurchasesFailed.Broadcast(-1, "查询失败");
            NSLog(@"QueryRestoredPurchases查询失败");
        }
    }];
}

void XDPaymentIOS::CheckRefundStatus(){
    dispatch_async(dispatch_get_main_queue(), ^{
        [XDPayment checkRefundStatus:^(XDGRepayMentCode code, NSString * _Nullable msg, NSDictionary * _Nullable data) {
            [XDUE4PaymentTool bridgeRefundStatusWithCode:code msg:msg data:data];
             NSLog(@"check status %@", msg?:@"");
        }];
    });     
}


void XDPaymentIOS::CheckRefundStatusWithUI(){
    dispatch_async(dispatch_get_main_queue(), ^{
        [XDPayment checkRefundStatusWithUI:^(XDGRepayMentCode code, NSString * _Nullable msg, NSDictionary * _Nullable data) {
            [XDUE4PaymentTool bridgeRefundStatusWithCode:code msg:msg data:data];
            NSLog(@"check UI %@", msg?:@"");
        }];
    });    
}

void XDPaymentIOS::PayWithWeb(FString orderId,
                    FString productId,
                    FString productName,
                    float  payAmount,
                    FString roleId,
                    FString serverId,
                    FString ext){
   //空，只有安卓有这个
}


//-------ios 源代码-------
@implementation XDUE4PaymentTool

+(NSArray*)getProductIdList:(NSString*)listJson{
    if (listJson == nil || listJson.length == 0) {
        return nil;
    }else{
        NSLog(@"解析 Product List %@", listJson);
        NSData *jsonData = [listJson dataUsingEncoding:NSUTF8StringEncoding];
        NSError *err;
        NSDictionary* dic = [NSJSONSerialization JSONObjectWithData:jsonData
                                                            options:NSJSONReadingMutableContainers
                                                              error:&err];
        if (dic != nil) {
            id ary = [dic objectForKey:@"list"];
            if ([ary isKindOfClass:[NSArray class]]) {
                return ary;
            }
        }
        return nil;
    }
}


+ (void)bridgePayCallback:(XDOrderInfo *)orderInfo error:(NSError *)error {
    if (error != nil) {
        FXDPaymentModule::OnXDSDKPaymentFailed.Broadcast((int)error.code, UTF8_TO_TCHAR([error.localizedDescription?:@"" UTF8String]));
        NSLog(@"iOS支付失败了, code: %d, msg: %@", error.code, error.localizedDescription?:@"");
   
    }else if(orderInfo != nil){
        NSString* orderId = orderInfo.outTradeNo?:@"";
        NSString* productId = orderInfo.productIdentifier?:@"";
        NSString* serverId = orderInfo.serverId?:@"";
        NSString* roleId = orderInfo.roleId?:@"";
        FXDPaymentModule::OnXDSDKPaymentSucceed.Broadcast(UTF8_TO_TCHAR([orderId UTF8String]), UTF8_TO_TCHAR([productId UTF8String]), UTF8_TO_TCHAR([serverId UTF8String]), UTF8_TO_TCHAR([roleId UTF8String]));
        NSLog(@"成功了 orderId: %@, productId: %@", orderId, productId);
    }else{
        FXDPaymentModule::OnXDSDKPaymentFailed.Broadcast(-1, "失败");
         NSLog(@"失败了2");
    }
}

+ (void)bridgeRefundStatusWithCode:(XDGRepayMentCode)code msg:(NSString *)msg data:(NSDictionary *)data{
    if (code == XDGRepayMentCodeOk) {
        NSMutableDictionary *resultDict = [NSMutableDictionary dictionary];
        resultDict[@"data"] = data?:@{};
        NSString* strJson = resultDict.tdsglobal_jsonString;
        FXDPaymentModule::OnXDSDKCheckRefundStatusSucceed.Broadcast(UTF8_TO_TCHAR([strJson UTF8String]));
        NSLog(@"检查补款结果: %@", strJson);
    }else{
        FXDPaymentModule::OnXDSDKCheckRefundStatusFailed.Broadcast(-1, UTF8_TO_TCHAR([msg?:@"" UTF8String]));
        NSLog(@"失败了: %@", msg?:@"");
    }
}

+ (NSString *)randomStr{
    char datas[32];
    char _randomStr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int x=0;x<32;datas[x++] =_randomStr[arc4random()%62]); //71
    return [[NSString alloc] initWithBytes:datas length:32 encoding:NSUTF8StringEncoding];
}

@end

#endif