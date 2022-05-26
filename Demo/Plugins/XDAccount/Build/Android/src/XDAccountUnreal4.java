package com.xd;

import com.xd.XDCommonUnreal4;
import android.util.Log;
import com.tds.common.bridge.utils.BridgeJsonHelper;
import com.xd.cn.account.XDAccount;
import com.xd.cn.account.entity.LoginEntryType;
import com.xd.cn.common.base.XDError;
import com.xd.cn.common.bean.XDUser;
import com.xd.cn.common.callback.Callback;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import android.os.Handler;
import android.os.Looper;

public class XDAccountUnreal4 {

    public static void login() {
        //要在主线程执行
        new Handler(Looper.getMainLooper()).post(new Runnable() {
            @Override
            public void run() {
                 print("点击自带弹框登录");
                 XDAccount.loginWithPolicy();
            }
        });
    }

    public static void loginByType(String loginType) {
         //要在主线程执行
        new Handler(Looper.getMainLooper()).post(new Runnable() {
            @Override
            public void run() {
                LoginEntryType type = getLoginType(loginType);
                print("点击单点登录 LoginByType:  " + type.getName());
                XDAccount.loginWithPolicyByType(type);
            }
        });
    }

    public static void logout() {
        print("点击退出登录");
        XDAccount.logout();
    }

    private static LoginEntryType getLoginType(String loginType){
        for(LoginEntryType t : LoginEntryType.values()){
            if (t.getName().equalsIgnoreCase(loginType)){
                return t;
            }
        }
        return LoginEntryType.DEFAULT;
    }

    public static void openUserCenter() {
        print("打开用户中心");
        XDAccount.openUserCenter();
    }

    public static void getUser() {
        XDAccount.getUser(new Callback<XDUser>() {
            @Override
            public void onCallback(XDUser user, XDError tdsServerError) {
               if (user != null){
                   String json = constructorUserForBridge(user, tdsServerError);
                   print("获取用户信息: " + json);

                   XDCommonUnreal4.nativeOnXDSDKGetUserCompleted(1, json);
               }else{
                   XDCommonUnreal4.nativeOnXDSDKGetUserCompleted(0, TEXT("获取用户信息失败"));
                   print("获取用户信息失败， user 是 null");
               }
            }
        });
    }

    public static void accountCancellation() {
        print("打开注销页面。");
        XDAccount.accountCancellation();
    }

    private static String constructorUserForBridge(XDUser xdUser, XDError tdsServerError) {
        Map<String, Object> callbackParams = new HashMap<>(2);
        if (xdUser != null) {
            Map<String, Object> tdsUserParams = new HashMap<>(7);
            tdsUserParams.put("userId", xdUser.getId());
            tdsUserParams.put("name", xdUser.getName());
            tdsUserParams.put("nickName", xdUser.getNickName());
            tdsUserParams.put("avatar", xdUser.getAvatar());
            tdsUserParams.put("loginType", xdUser.getLoginTypeName());
            List<String> boundAccounts;
            if (xdUser.getBoundAccounts() == null) {
                boundAccounts = new ArrayList<String>();
            } else {
                boundAccounts = xdUser.getBoundAccounts();
            }
            tdsUserParams.put("boundAccounts", boundAccounts);

            Map<String, Object> tokenParams = new HashMap<>(5);
            tokenParams.put("kid", xdUser.getAccessToken().getKid());
            tokenParams.put("accessToken", xdUser.getAccessToken().getKid());
            tokenParams.put("tokenType", xdUser.getAccessToken().getTokenType());
            tokenParams.put("macKey", xdUser.getAccessToken().getMacKey());
            tokenParams.put("macAlgorithm", xdUser.getAccessToken().getMacAlgorithm());
            tdsUserParams.put("token", tokenParams);

            String resultJson = BridgeJsonHelper.object2JsonString(tdsUserParams);
            print("打印用户信息: " + resultJson);
            return resultJson;
            
        }else{
            Map<String, Object> tdsErrorParams = new HashMap<>(2);
            tdsErrorParams.put("code", tdsServerError.getCode());
            tdsErrorParams.put("error_msg", tdsServerError.getMessage());
            String resultJson = BridgeJsonHelper.object2JsonString(tdsErrorParams);

            print("用户信息获取失败: " + resultJson);
            return resultJson;
        }       
    }

    private static void print(String msg){
        Log.i("a","a");
        Log.i("==sdk log Account==\n", msg);
    }

}
