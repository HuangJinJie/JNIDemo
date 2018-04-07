#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_mutillibs_JNI_stringFromJNITwo(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "I am From libary Two";
    return env->NewStringUTF(hello.c_str());
}








