package com.example.guolu;

import android.os.Build;
import android.os.SystemClock;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

public class MainActivity extends AppCompatActivity {
    private static String TAG = MainActivity.class.getSimpleName();
    private JNI jni;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        final PressureView pressureView = new PressureView(this);
        setContentView(pressureView);
        jni = new JNI();
        Log.e(TAG, "string: " + jni.stringFromJNI());
        new Thread() {
            @Override
            public void run() {
                super.run();
                while (true) {
                    SystemClock.sleep(500);
                    int pressure = Math.abs(jni.getPressure());//0~250
                    Log.e(TAG, "pressure: "+pressure);
                    pressureView.setPressure(pressure);

                    if (pressure > 220) {//如果压力大于220就要爆炸
                        break;
                    }
                }


            }
        }.start();

        uninstallLisetner("/data/data/com.example.guolu", Build.VERSION.SDK_INT);
    }

    public native void uninstallLisetner(String packName, int sdkVersion);
}
