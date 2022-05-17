package com.xd;

import com.tds.common.bridge.BridgeCallback;
import com.tds.common.bridge.IBridgeService;
import com.tds.common.bridge.annotation.BridgeMethod;
import com.tds.common.bridge.annotation.BridgeParam;
import com.tds.common.bridge.annotation.BridgeService;
import com.tds.common.bridge.BridgeCallback;
import com.tds.common.bridge.utils.BridgeJsonHelper;
import com.xd.cn.payment.XDPayment;
import com.xd.cn.payment.callback.XDPaymentCallback;

import java.util.HashMap;
import java.util.Map;

public class XDPaymentUnreal4 {

    public void pay(String orderId,
            String productId,
            String productName,
            float payAmount,
            String roleId,
            String serverId,
            String ext) {
        XDPayment.pay(orderId, productId, productName, payAmount, roleId, serverId, ext, new XDPaymentCallback() {
            @Override
            public void onPaymentResult(int code, String message) {
                nativeOnXDSDKPayWithWebCompleted(code, message);
            }
        });
    }
   
    // ------JNI 回调-------
    public native static void nativeOnXDSDKPayWithWebCompleted(int code, String msg);

}
