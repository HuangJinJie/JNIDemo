/**
 * 让C代码调用Java类中的方法
 */
#include <jni.h>
#include <string>

#include <android/log.h>
#define LOG_TAG "CCallJava"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

extern "C"


/**
 * 让C代码调用Java中JNI类的 public int add(int x,int y)
 */
JNIEXPORT void

JNICALL
Java_com_example_administrator_hellowjni_JNI_callbackAdd(
        JNIEnv *env,
        jobject /* this */) {
    //1.得到字节码
    jclass jclazz = env->FindClass("com/example/administrator/hellowjni/JNI");
    /**
     * 2.得到方法
     * jmethodID GetMethodID(jclass clazz, const char* name, const char* sig)
     * 最后一个参数是签名
     */
    jmethodID jmethodIDs = env->GetMethodID(jclazz,"add","(II)I");

    //3.实例化该类
    jobject jobject = env->AllocObject(jclazz);

    //4.调用方法
    jint value = env->CallIntMethod(jobject,jmethodIDs,99,5);
    //成功调用了public int add(int x,int y)
    printf("1.value===%d\n",value);
    LOGE("2.value===%d\n",value);
}

extern "C"
/**
 * 让C代码调用void printString(String s)
 */
JNIEXPORT void JNICALL Java_com_example_administrator_hellowjni_JNI_callbackPrintString
        (JNIEnv * env, jobject job){
    //1.得到字节码
    //jclass      (*FindClass)(JNIEnv*, const char*);
    jclass jclazz = env->FindClass("com/example/administrator/hellowjni/JNI");
    //2.得到方法
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    //最后一个参数是方法签名
    jmethodID jmethodIDs= env->GetMethodID(jclazz,"printString","(Ljava/lang/String;)V");
    //3.实例化该类
    // jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject  jobject =env->AllocObject(jclazz);
    //4.调用方法
    //void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    //jstring     (*NewStringUTF)(JNIEnv*, const char*);
    jstring jst = env->NewStringUTF("I am afu!!!(*env)->");
    env->CallVoidMethod(jobject,jmethodIDs,jst);
    //成功调用了public void helloFromJava()
};


extern "C"
/**
 * 让C代码静态方法 static void sayHello(String s)
 */
JNIEXPORT void JNICALL Java_com_example_administrator_hellowjni_JNI_callbackSayHello
        (JNIEnv * env, jobject jobj){

    //1.得到字节码
    //jclass      (*FindClass)(JNIEnv*, const char*);
    jclass jclazz = env->FindClass("com/example/administrator/hellowjni/JNI");
    //2.得到方法
    //jmethodID   (*GetStaticMethodID)(JNIEnv*, jclass, const char*, const char*);
    //最后一个参数是方法签名
    jmethodID jmethodIDs= env->GetStaticMethodID(jclazz,"sayHello","(Ljava/lang/String;)V");
    jstring jst = env->NewStringUTF("I am android1223");
    env->CallStaticVoidMethod(jclazz,jmethodIDs,jst);
    //成功调用了static void sayHello(String s)

}


//extern "C"  //Toast.makeText(MainActivity.this,"showToast----------------",Toast.LENGTH_SHORT).show();会报控制针异常
///**
// * instance:谁调用了当前Java_com_atguigu_ccalljava_JNI_callBackShowToast对应的Java的接口
// * 就是谁的实例：当前是JNI.this-->MainActivity.this
// */
//JNIEXPORT void JNICALL Java_com_example_administrator_hellowjni_MainActivity_callBackShowToast(JNIEnv * env, jobject instance) {
//    //1.得到字节码
//    //jclass      (*FindClass)(JNIEnv*, const char*);
//    jclass jclazz = env->FindClass("com/example/administrator/hellowjni/MainActivity");
//    //2.得到方法
//    //最后一个参数是方法签名
//    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
//    jmethodID jmethodIDs= env->GetMethodID(jclazz,"showToast","()V");
//    //3.实例化该类
//    //   jobject     (*AllocObject)(JNIEnv*, jclass);
//    jobject  jobject1 = env->AllocObject(jclazz);
//    //4.调用方法
//    //void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
//    env->CallVoidMethod(jobject1,jmethodIDs);
//    //成功调用了static void sayHello(String s)
//
//}



/**
 * instance:谁调用了当前Java_com_atguigu_ccalljava_JNI_callBackShowToast对应的Java的接口
 * 就是谁的实例：当前是JNI.this-->MainActivity.this
 */
extern "C"
JNIEXPORT void JNICALL Java_com_example_administrator_hellowjni_MainActivity_callBackShowToast(JNIEnv *env, jobject instance) {

    //1.得到字节码
    //jclass      (*FindClass)(JNIEnv*, const char*);
    jclass jclazz = env->FindClass("com/example/administrator/hellowjni/MainActivity");
    //2.得到方法
    //最后一个参数是方法签名
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    jmethodID jmethodIDs= env->GetMethodID(jclazz,"showToast","()V");
    //3.实例化该类
    //   jobject     (*AllocObject)(JNIEnv*, jclass);
    //jobject  jobject1 = (*env)->AllocObject(env,jclazz);
    //4.调用方法
    //void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    env->CallVoidMethod(instance,jmethodIDs);
    //成功调用了static void sayHello(String s)

}













