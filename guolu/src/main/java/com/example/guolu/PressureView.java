package com.example.guolu;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.View;

/**
 *  Jacket
 *
 */
public class PressureView extends View {
    /**
     * 锅炉压力值
     */
    private int pressure;
    private Paint paint;

    public PressureView(Context context) {
        super(context);
        paint = new Paint();
        paint.setAntiAlias(true);//设置抗锯齿
        paint.setTextSize(25);
    }


    public void setPressure(int pressure) {
        this.pressure = pressure;
//        invalidate();//在主线程中调用
        postInvalidate();//onDraw()执行

    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);

        if(pressure > 220){
            //1.如果压力值大于220，就绘制文本，显示锅炉爆炸了，刚哥快跑
            canvas.drawText("刚哥快跑！！，要爆了！",10,getHeight()/2,paint);
        }else{

            //2.正常和提示的情况
            //设置背景颜色为灰色
            paint.setColor(Color.GRAY);
            canvas.drawRect(10,10,60,260,paint);
            //2.1如果是小于200正常显示，并且设置画笔颜色，绿色
            if(pressure < 200){
                paint.setColor(Color.GREEN);
                canvas.drawRect(10, 260-pressure, 60, 260, paint);
            }else if(pressure>=200){
                //2.2如果是大于200警示给看护者，并且设置画笔颜色，红色
                paint.setColor(Color.RED);
                canvas.drawRect(10, 260-pressure, 60, 260, paint);
            }

        }



    }
}
