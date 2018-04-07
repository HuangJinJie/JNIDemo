package com.example.jnisomodel;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;

import com.example.administrator.hellowjni.JNI;

public class MainActivity extends AppCompatActivity {

    private JNI jni;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        jni = new JNI();
        jni.stringFromJNI();
        jni.sayHello();

        jni.myNativeJNIMethodWithLog(); //在c++代码中实现带Log.e打印日志

        jni.callbackAdd();
        jni.callbackPrintString();
        jni.callbackSayHello();
    }
}
