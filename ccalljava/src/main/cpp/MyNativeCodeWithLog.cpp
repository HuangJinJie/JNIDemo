#include <jni.h>
#include <string>
#include <android/log.h>

#define LOG_TAG "MyNativeCodeWithLog"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)


/**
 * jstring ：返回值
 * Java_全类名_方法名
 * JNIEnv* env:里面有很多方法
 * jobject jobj：谁调用了这个方法就是谁的实例
 * 当前就是JNI.thi
 */
extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_administrator_hellowjni_JNI_myNativeJNIMethodWithLog(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "I am From mynativecode!";
//    jint value = 3;
//    printf("value===%d\n",value);
    LOGE("\nc函数中打印Log.e666\n");
    return env->NewStringUTF(hello.c_str());
}








