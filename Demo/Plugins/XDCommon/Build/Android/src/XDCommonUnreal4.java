package com.xd;

import static com.xd.cn.common.constants.Constants.USER_STATUS_RESULT.BIND_CHANGE_CODE;
import static com.xd.cn.common.constants.Constants.USER_STATUS_RESULT.UNBIND_CHANGE_CODE;
import android.app.Activity;
import android.content.res.Configuration;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.Display;
import android.view.View;
import com.xd.cn.common.bridge.XDCallbackType;
import com.tds.common.bridge.utils.BridgeJsonHelper;
import com.xd.cn.common.XDSDK;
import com.xd.cn.common.base.XDCallback;
import com.xd.cn.common.bean.XDUser;
import com.xd.cn.common.config.ServerConfig;
import com.xd.cn.common.config.XDConfig;
import com.xd.cn.common.entities.TapSdkConfig;
import com.xd.cn.common.global.GlobalConfigStore;
import com.xd.cn.common.widget.TDSToastManager;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class XDCommonUnreal4 {

    private static int width = -1;
    private static int height = -1;
    public static int orientation = -1;

    public static void initSDK(final Activity activity, String clientId, int orientation) {
        print("初始化: " + clientId + ".  orientation: " + orientation);

        setCallback(); //绑定回调
        XDConfig xdConfig = new XDConfig.Builder()
                .setClientId(clientId)
                .setOrientation(orientation)
                .build();
        XDSDK.initSDK(activity, xdConfig);
    }

    private static void setCallback() {
        XDSDK.setCallback(new XDCallback() {
            @Override
            public void onInitSuccess() {
                ServerConfig serverConfig = GlobalConfigStore.INSTANCE.getServerConfig();
                if (serverConfig != null) {
                    TapSdkConfig cfg = serverConfig.tapSdkConfig;
                    if (cfg != null) {
                        Map<String, Object> resultMap = new HashMap<>(2);
                        resultMap.put("channel", serverConfig.channel);
                        resultMap.put("tapSdkConfig", cfg);

                        processCallback(XDCallbackType.InitSuccess, resultMap, "");
                        return;
                    }
                }

                processCallback(XDCallbackType.InitFail, null, "Android tapSdkConfig error");
            }

            @Override
            public void onInitFailed(String msg) {
                processCallback(XDCallbackType.InitFail, null, msg);
            }

            @Override
            public void onLoginSuccess(XDUser xdUser) {
                if (xdUser != null) {
                    processCallback(XDCallbackType.LoginSucceed, constructorUserForBridge(xdUser), "");
                } else {
                    processCallback(XDCallbackType.LoginFailed, null, "登录失败 用户信息是空");
                    Log.e("XDSDK LOG: ", "onLoginSuccess XDUser 是空");
                }
            }

            @Override
            public void onLoginFailed(String msg) {
                processCallback(XDCallbackType.LoginFailed, null, msg);
            }

            @Override
            public void onLoginCanceled() {
                processCallback(XDCallbackType.LoginCancel, null, "");
            }

            @Override
            public void onLogoutSucceed() {
                processCallback(XDCallbackType.LogoutSucceed, null, "");
            }

            @Override
            public void onProtocolAgreed() {
                processCallback(XDCallbackType.AgreeProtocol, null, "");
            }

            @Override
            public void onSwitchAccount() {
                processCallback(XDCallbackType.SwitchAccount, null, "");
            }

            @Override
            public void onInterruptRealName() {
                processCallback(XDCallbackType.InterruptByRealName, null, "");

            }

            @Override
            public void onUserStatusChanged(int code, String msg) {
                Map<String, Object> resultMap = new HashMap<>(1);
                resultMap.put("platform", msg);

                if (code == BIND_CHANGE_CODE) {
                    processCallback(XDCallbackType.UserStateChangeCodeBindSuccess, resultMap, "");

                } else if (code == UNBIND_CHANGE_CODE) {
                    processCallback(XDCallbackType.UserStateChangeCodeUnBindSuccess, resultMap, "");

                } else {
                    Log.e("XDSDKCommon", "onUserStatusChanged 出错 " + msg);
                }
            }
        });
    }


    @SuppressWarnings("SameParameterValue")
    private static void processCallback(XDCallbackType type, Map<String, Object> result, String errorMsg) {
        print("收到全局回调: " + type + "  \n msg: " + errorMsg);

        if (type == XDCallbackType.LoginSucceed){
            String json = BridgeJsonHelper.object2JsonString(result);
            nativeOnXDSDKLoginCompleted(1, json); //登录成功

        }else if (type == XDCallbackType.LoginFailed){
            nativeOnXDSDKLoginCompleted(0, "登录失败");

        }else if (type == XDCallbackType.LoginCancel){
            nativeOnXDSDKLoginCompleted(-1, "登录取消");

        }else if (type == XDCallbackType.LogoutSucceed){
            nativeOnXDSDKLogoutSuccess();

        }else if (type == XDCallbackType.SwitchAccount){
            nativeOnXDSDKSwitchAccount();

        }else if (type == XDCallbackType.AgreeProtocol){
            nativeOnXDSDKAgreeProtocol();

        }else if (type == XDCallbackType.InitSuccess){
            nativeOnXDSDKInitCompleted(true);

        }else if (type == XDCallbackType.InitFail){
            nativeOnXDSDKInitCompleted(false);

        }else if (type == XDCallbackType.InterruptByRealName){
            nativeOnXDSDKInterruptByRealName();

        }else if (type == XDCallbackType.UserStateChangeCodeBindSuccess){
            nativeOnXDSDKBindSuccess();

        }else if (type == XDCallbackType.UserStateChangeCodeUnBindSuccess){
            nativeOnXDSDKUnBindSuccess();
        }
    }

    private static Map<String, Object> constructorUserForBridge(XDUser xdUser) {
        Map<String, Object> callbackParams = new HashMap<>(2);
        if (xdUser != null) {
            Map<String, Object> tdsUserParams = new HashMap<>(7);
            tdsUserParams.put("userId", xdUser.getId());
            tdsUserParams.put("name", xdUser.getName());
            tdsUserParams.put("loginType", xdUser.getLoginTypeName());
            tdsUserParams.put("nickName", xdUser.getNickName());
            tdsUserParams.put("avatar", xdUser.getAvatar());
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
            callbackParams.put("user", tdsUserParams);
        }

        return callbackParams;
    }


    public static String getSDKVersionName(){
        String v = XDSDK.getVersionName();
        print("点击 getSDKVersionName: " + v);
        return v;
    }

    public static boolean isInitialized(){
        boolean isInit = XDSDK.isInitialized();
        print("点击是否初始化: " + isInit);
        return isInit;
    }

    public static void report(String serverId, String roleId, String roleName){
        print("点击 report:" + serverId + " roleId:" + roleId + " roleName:" + roleName);
        XDSDK.report(serverId, roleId, roleName);
    }

    public static void enterGame() {
        print("执行 enterGame");
        XDSDK.enterGame();
    }

    public static void leaveGame() {
        print("执行 leaveGame");
        XDSDK.leaveGame();
    }

    public static int getAntiAddictionAgeRange() {
        int ageRange = XDSDK.getAntiAddictionAgeRange();
        print("ageRange 结果: " + ageRange);
        return ageRange;
    }

    public static void showLoading(Activity activity) {
        TDSToastManager.instance().showLoading(activity);
    }

    public static void hideLoading() {
        TDSToastManager.instance().dismiss();
    }

    // 下面是与SDK无关方法
    public static void onCreate(final Activity activity) {
        Display display = activity.getWindowManager().getDefaultDisplay();
        DisplayMetrics dm = new DisplayMetrics();
        display.getRealMetrics(dm);

        if(activity.getResources().getConfiguration().orientation == Configuration.ORIENTATION_LANDSCAPE){
            width = dm.widthPixels;
            height = dm.heightPixels;
        }
    }

    public static void onStop(final Activity activity) {

    }

    public static void onResume(View ueContainerView, final Activity activity) {
        if(width <= 0 || height <= 0 || width < height){
            return;
        }
        ueContainerView.getLayoutParams().width = width;
        ueContainerView.getLayoutParams().height = height;
    }

    private static void print(String msg){
        Log.e("====== sdk log ====== \n", msg);
    }


    //------JNI 回调-------
    public native static void nativeOnXDSDKInitCompleted(boolean success);

    public native static void nativeOnXDSDKLoginCompleted(int code, String userJson);

    public native static void nativeOnXDSDKGetUserCompleted(int code, String userJson);

    public native static void nativeOnXDSDKLogoutSuccess();

    public native static void nativeOnXDSDKSwitchAccount();

    public native static void nativeOnXDSDKAgreeProtocol();

    public native static void nativeOnXDSDKInterruptByRealName();

    public native static void nativeOnXDSDKBindSuccess();

    public native static void nativeOnXDSDKUnBindSuccess();

}
