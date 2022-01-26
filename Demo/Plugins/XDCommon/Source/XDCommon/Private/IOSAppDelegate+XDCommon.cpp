// Fill out your copyright notice in the Description page of Project Settings.

#if PLATFORM_IOS

#import "IOSAppDelegate+XDCommon.h"
#import <objc/runtime.h>
#import <XDCommonSDK/XDSDK.h>

@implementation IOSAppDelegate (XDCommon)

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    //为了在类别方法里执行原来的方法--start
    u_int count;
    Method * methods = class_copyMethodList([self class], &count);
    NSInteger index = -1;
    
    for (int i=0; i<count; i++) {
        SEL sel = method_getName(methods[i]);
        NSString* strName = [NSString stringWithCString:sel_getName(sel) encoding:NSUTF8StringEncoding];
        if ([strName isEqualToString:@"application:didFinishLaunchingWithOptions:"]) {
            index = i;
        }
    }
    
    if(index >= 0 && index < count){
        SEL sel = method_getName(methods[index]);
        IMP imp = method_getImplementation(methods[index]);
        ((void (*)(id, SEL, id, id))imp)(self, sel, application, launchOptions);
    }
    //为了在类别方法里执行原来的方法--end

    //Debug 模式会输出日志，以及开启第三方 SDK 的 debug 模式
    [XDSDK setDebugMode:YES];

    [XDSDK application:application didFinishLaunchingWithOptions:launchOptions];
    return YES;
}


- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options{
    
    [XDSDK application:app openURL:url options:options];
    return YES;
}

- (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray<id<UIUserActivityRestoring>> * _Nullable))restorationHandler {
    [XDSDK application:application continueUserActivity:userActivity restorationHandler:restorationHandler];
    return YES;
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
    [XDSDK application:application didReceiveRemoteNotification:userInfo fetchCompletionHandler:completionHandler];
}


- (void)scene:(UIScene *)scene openURLContexts:(NSSet<UIOpenURLContext *> *)URLContexts API_AVAILABLE(ios(13.0)){
    [XDSDK scene:scene openURLContexts:URLContexts];
}

- (void)scene:(UIScene *)scene continueUserActivity:(NSUserActivity *)userActivity  API_AVAILABLE(ios(13.0)){
    [XDSDK scene:scene continueUserActivity:userActivity];
}


#pragma mark --TODO 新增
-(UIInterfaceOrientationMask)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window{
    return  [XDSDK application:application supportedInterfaceOrientationsForWindow:window];
}

@end

#endif