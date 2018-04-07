#include <jni.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <android/log.h>
#include <string.h>

#define LOG_TAG "GuoLu"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_guolu_JNI_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from GuoLu";
    return env->NewStringUTF(hello.c_str());
}

/**
 * 把一个jstring转换成一个c语言的char* 类型.
 */
char *_JString2CStr(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("GB2312");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid,
                                                         strencode); // String .getByte("GB2312");
    jsize alen = env->GetArrayLength(barr);
    jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1); //"\0"
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    return rtn;
}

/**
 得到锅炉的压力值
 0~250之间
*/

int pressure = 20;

int getPressure() {
    int incease = rand() % 20;
    pressure += incease;
    return pressure;
}


extern "C"
JNIEXPORT jint

JNICALL
/**
 * 从锅炉感应器中得到锅炉压力值
 */
Java_com_example_guolu_JNI_getPressure(JNIEnv *env, jobject instance) {
    int pressur = getPressure();
    return pressur;
}


extern "C"
JNIEXPORT void

JNICALL
Java_com_example_guolu_MainActivity_uninstallLisetner(JNIEnv *env, jobject instance,
                                                      jstring jstrpackName, jint sdkVersion) {
    //返回三个值，大于0，父进程的id,等于0就是子进程的id,负数就是出错了
    int code = fork();
    if (code == 0) {
        //判断软件是否被卸载
        LOGE("child==%d\n", code);
        int flag = 1;
        while (flag) {
            sleep(1);//1秒
            //FILE	*fopen(const char *, const char *);
            char *packName = _JString2CStr(env, jstrpackName);
//            FILE* file = fopen("/data/data/com.atguigu.guolu","r");// /data/data/com.example.guolu
            FILE *file = fopen(packName, "r");// /data/data/com.example.guolu
            if (file == NULL) {
                //应用对应的包名文件夹不存在, 说明已经被卸载了
//                 if(sdkVersion <17){
//                     execlp("am", "am", "start", "-a", "android.intent.action.VIEW", "-d", "http://10.0.2.2:8080/uninstall.html", NULL);
//
//                 }else{
//                     execlp("am", "am", "start", "--user", "0", "-a","android.intent.action.VIEW", "-d","http://10.0.2.2:8080/uninstall.html", (char*) NULL);
//                 }
                LOGE("软件被卸载");
                execlp("am", "am", "start", "--user", "0", "-a", "android.intent.action.VIEW", "-d",
                       "https://www.baidu.com", (char *) NULL);
//                 execlp("am", "am", "start", "-a", "android.intent.action.VIEW", "-d", "http://10.0.2.2:8080/uninstall.html", NULL);

                flag = 0;//停止循环
            } else {
                LOGE("软件没卸载");
            }

        }


    } else if (code > 0) {
        //父进程
        LOGE("father==%d\n", code);
    } else {
        //出错了
        LOGE("error==%d\n", code);
    }

//     //返回大于0的值和等于0的值
//     int code =fork();
//     if(code >0){
//         LOGD("子进程的id为%d \n",code);
//     }else if(code==0){
//         LOGD("子进程启动成功 \n");
//         //监听被卸载
//         int flag = 1;
//         FILE* file;
//         while(flag){
//             sleep(1);
//             //得到当前应用的包名字符串
//             char * packageDir = _JString2CStr(env, sdkVersion);
//             //FILE	*fopen(const char *, const char *);
//              file = fopen(packageDir, "r");
//             if(file == NULL){
//                 flag = 0;
//                 LOGD("当前应用被卸载了, 准备启动调查问卷 \n");
//                 if(sdkVersion>=17) {
//                     execlp("am", "am", "start", "--user", "0", "-a","android.intent.action.VIEW", "-d","http://www.baidu.com", (char*) NULL);
//                 } else {
//                     execlp("am", "am", "start", "-a", "android.intent.action.VIEW", "-d", "http://www.baidu.com", NULL);
//                 }
//             }
//         }
//     }else{
//         LOGD("子进程启动失败 \n");
//     }


}