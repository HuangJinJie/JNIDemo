package com.example.guolu;

/**
 * <pre>
 *     author : Administrator (Jacket)
 *     e-mail : 378315764@qq.com
 *     time   : 2018/01/11
 *     desc   :
 *     version: 1.0
 * </pre>
 */

public class JNI {
    static {
        System.loadLibrary("guolu");
    }
    public native String stringFromJNI();
    public native int getPressure();
}
