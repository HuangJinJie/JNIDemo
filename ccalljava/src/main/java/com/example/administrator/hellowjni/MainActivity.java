package com.example.administrator.hellowjni;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private static String TAG = MainActivity.class.getSimpleName();//这里TAG声明为静态变量，避免c/c++函数多次实例化MainActivity对象时候创建出多个TAG，这样打印效果不好

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private JNI jni;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        jni = new JNI();
        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(jni.stringFromJNI());
        TextView tvHellow = (TextView) findViewById(R.id.hello_text);
        tvHellow.setText(jni.sayHello());

        TextView myNativeMethod = (TextView) findViewById(R.id.my_native_method);
        myNativeMethod.setText(jni.myNativeJNIMethodWithLog()); //在c++代码中实现带Log.e打印日志

        jni.callbackAdd();
        jni.callbackPrintString();
        jni.callbackSayHello();
    }



    public void onClick(View view){
        MainActivity.this.callBackShowToast();
    }

    public native void callBackShowToast();

    public void showToast(){
        Log.e(TAG, "showToast: ");
        Toast.makeText(MainActivity.this,"showToast----------------",Toast.LENGTH_SHORT).show();
    }

}
