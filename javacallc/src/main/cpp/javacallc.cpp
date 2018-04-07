#include <jni.h>
#include <string>
#include <string.h>
#include <android/log.h>
#include <malloc.h>
#include <stdio.h>

#define LOG_TAG "javacallc"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

/**
 * jint：返回值
 * Java_全类名_方法名
 * JNIEnv *env：
 */
extern "C"
JNIEXPORT jint

JNICALL
Java_com_example_javacallc_JNI_add(JNIEnv*env, jobject jobj, jint ji, jint jj){
    int result = ji + jj;
    LOGE("result===%d\n",result);
    return result;
};

/**
 * 将一个jstring转换成一个c语言的char* 类型.
 */
char* _JString2CStr(JNIEnv* env, jstring jstr) {
    char* rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("GB2312");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray)env->CallObjectMethod(jstr, mid, strencode); // String .getByte("GB2312");
    jsize alen = env->GetArrayLength(barr);
    jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if(alen > 0) {
        rtn = (char*)malloc(alen+1); //"\0"
        memcpy(rtn, ba, alen);
        rtn[alen]=0;
    }
    env->ReleaseByteArrayElements(barr, ba,0);
    return rtn;
}


/**
 *  从java传入字符串，C代码进程拼接
     *
     * @param java : I am from java
     *        c    : add I am from C
     * @return  I am form java add I am from C
 */
extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_javacallc_JNI_sayHello(JNIEnv * env, jobject job, jstring jstr){

    char* fromJava = _JString2CStr(env,jstr);//I am form java add I am from C   注意_JString2CStr函数要在调用之前声明，这是C/C++的语法规则，和Java不一样...
    //c:
    char* fromC = "add I am from C";
    //拼接函数strcat
    strcat(fromJava,fromC);//把拼接的结果放在第一参数里面
    //jstring     (*NewStringUTF)(JNIEnv*, const char*);
    LOGE("fromJava===%s\n",fromJava);
    return  env->NewStringUTF(fromJava);
};


/*
 * Class:     com_example_javacallc_JNI
 * Method:    increaseArrayEles
 * Signature: ([I)[I
 * 给每个元素加上10
 */
extern "C"
JNIEXPORT jintArray JNICALL Java_com_example_javacallc_JNI_increaseArrayEles
        (JNIEnv * env, jobject jobject1, jintArray jarray){

    //1.得到数组的长度
    //jsize       (*GetArrayLength)(JNIEnv*, jarray);
    jsize size = env->GetArrayLength(jarray);
    //2.得到数组元素(方法是先获得数组的指针，通过指针修改)
    //jint*       (*GetIntArrayElements)(JNIEnv*, jintArray, jboolean*);
    jint*  intArray = env->GetIntArrayElements(jarray,JNI_FALSE);
    //3.遍历数组，给每个元素加上10
    int i;
    for(i =0;i<size;i++){
//        *(intArray+i) = *(intArray+i) + 10;
        *(intArray+i) +=  10;
        LOGE("intArray[%d]===%d\n",i,*(intArray+i));
    }

    //4.调用SetXXArrayRegion方法提交到Java数组里面（如果不提交的话，不会修改Java数组元素的值）。http://blog.csdn.net/pz0605/article/details/53010556
    env->SetIntArrayRegion(jarray, 0,size,intArray);
    //5.返回结果
    return  jarray;
}


/*
 * Class:     com_example_javacallc_JNI
 * Method:    checkPwd
 * Signature: (Ljava/lang/String;)I
 */
extern "C"
JNIEXPORT jint JNICALL Java_com_example_javacallc_JNI_checkPwd
        (JNIEnv * env, jobject jobject1, jstring jstr){

    //服务器的密码是123456
    char* origin = "123456";
    char* fromUser = _JString2CStr(env,jstr);

    //函数比较字符串是否相同
    int code =  strcmp(origin,fromUser);
    LOGE("code===%d\n",code);
    if(code==0){
        return 200;
    }else{
        return 400;
    }
}




