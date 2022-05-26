package com.xd;

import android.content.SharedPreferences;
import android.util.Log;
import com.xd.cn.payment.XDPayment;
import com.xd.cn.payment.callback.XDPaymentCallback;
import com.xd.cn.common.utils.SP;

public class XDPaymentUnreal4 {

    public static void pay(String orderId,
                           String productId,
                           String productName,
                           float payAmount,
                           String roleId,
                           String serverId,
                           String ext) {

        //测试代码---start
        // orderId = "";
        // payAmount = 1.0f;
        // if (productId.equals("1")) {
        //     productId = "com.xd.sdkdemo1.stone60";
        //     payAmount = 30.0f;
        // } else if (productId.equals("2")) {
        //     productId = "com.xd.sdkdemo1.stone300";
        //     payAmount = 30.0f;
        // } else if (productId.equals("3")) {
        //     productId = "com.xd.sdkdemo1.stone500";
        //     payAmount = 50.0f;
        // } else if (productId.equals("4")) {
        //     productId = "com.xd.sdkdemo1.stone980";
        //     payAmount = 108.0f;
        // } else if (productId.equals("5")) {
        //     productId = "com.xd.sdkdemo1.stone1080";
        //     payAmount = 400.0f;
        // } else if (productId.equals("6")) {
        //     productId = "com.xd.sdkdemo1.stone5400";
        //     payAmount = 500.0f;
        // } else if (productId.equals("7")) {
        //     productId = "com.xd.sdkdemo1.package";
        //     payAmount = 999.0f;
        // } else {
        //     productId = "com.xd.sdkdemo1.stone30";
        //     payAmount = 1.0f;
        // }
        // productName = productId;
        // if (XDCommonUnreal4.tmpActivity != null) {
        //     SharedPreferences preferences = XDCommonUnreal4.tmpActivity.getPreferences(0);
        //     roleId = preferences.getString("demo_tmp_sp_userId", "");
        //     print("payment saved userId: " + roleId);
        // }
        //测试代码---end

        print("打开网页支付: " + "productId: " + productId + " roleId: " + roleId + "serverId: " + serverId);
        XDPayment.pay(orderId, productId, productName, payAmount, roleId, serverId, ext, new XDPaymentCallback() {
            @Override
            public void onPaymentResult(int code, String message) {
                if (code == 0) {
                    message = "支付完成";
                } else if (code == 1) {
                    message = "支付取消";
                } else if (code == 2) {
                    message = "支付处理中";
                }
                nativeOnXDSDKPayWithWebCompleted(code, message);
            }
        });
    }

    private static void print(String msg) {
        Log.i("a", "a"); //要加一个才能看到？
        Log.i("==sdk log Payment==\n", msg);
    }

    // ------JNI 回调-------
    public native static void nativeOnXDSDKPayWithWebCompleted(int code, String msg);

}
