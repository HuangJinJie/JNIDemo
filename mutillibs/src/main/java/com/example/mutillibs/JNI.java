package com.example.mutillibs;

/**
 * <pre>
 *     author : Administrator (Jacket)
 *     e-mail : 378315764@qq.com
 *     time   : 2018/01/12
 *     desc   :
 *     version: 1.0
 * </pre>
 */

public class JNI {
    static {
        System.loadLibrary("one");
        System.loadLibrary("two");
    }

    public native String stringFromJNIOne();
    public native String stringFromJNITwo();
}
