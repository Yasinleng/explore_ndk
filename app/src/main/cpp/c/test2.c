//
// Created by yasin on 2020/8/30.
//
#include <jni.h>

JNIEXPORT jstring JNICALL Java_com_yasin_explore_Jni_getString(JNIEnv *env, jobject thiz){
    return (*env)->NewStringUTF(env,"静态注册");
}

