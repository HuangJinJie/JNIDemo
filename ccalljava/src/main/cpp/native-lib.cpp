#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_administrator_hellowjni_JNI_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_administrator_hellowjni_JNI_sayHello(
        JNIEnv *env,
         jobject /* this */) {
    std::string sayHello = "sayHello";
    return env->NewStringUTF(sayHello.c_str());
}






