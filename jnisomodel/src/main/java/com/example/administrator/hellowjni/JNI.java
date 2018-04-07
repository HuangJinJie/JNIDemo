package com.example.administrator.hellowjni;

import android.util.Log;

/**
 * 注：要应用so文件作为库文件，对应的JNI类包名要一致
 * <pre>
 *     author : Administrator (Jacket)
 *     e-mail : 378315764@qq.com
 *     time   : 2018/01/11
 *     desc   :
 *     version: 1.0
 * </pre>
 */

public class JNI {

    private static String TAG = JNI.class.getSimpleName();//这里TAG声明为静态变量，避免c/c++函数多次实例化MainActivity对象时候创建出多个TAG，这样打印效果不好
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String myNativeJNIMethodWithLog();

    public native String sayHello();

    public native String stringFromJNI();

    /**
     * 当执行这个方法的时候，让C代码调用
     * public int add(int x, int y)
     */
    public native void callbackAdd();

    public native void callbackPrintString();

    public native void callbackSayHello();


    public int add(int x, int y) {
        Log.e(TAG, "add() x=" + x + " y=" + y);
        return x + y;
    }

    public void printString(String s){
        Log.e(TAG, "printString="+s);
    }

    public static void sayHello(String s){
        Log.e(TAG, "sayHello: "+s);
    }
}
