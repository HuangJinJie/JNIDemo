package com.example.mutillibs;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private JNI jni;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        jni = new JNI();

        TextView tvOne = (TextView) findViewById(R.id.tv_one);
        tvOne.setText(jni.stringFromJNIOne());

        TextView tvTwo = (TextView) findViewById(R.id.tv_two);
        tvTwo.setText(jni.stringFromJNITwo());
    }
}
