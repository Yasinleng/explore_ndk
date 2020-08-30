//
// Created by yasin on 2020/8/30.
//
#include <jni.h>
#include "print.h"


jstring getString(JNIEnv *env, jobject jobj){
    return (*env)->NewStringUTF(env,"动态注册");
}

jint getCount(JNIEnv *env, jobject jobj){
    return 5;
}

static const char * mClassName = "com/yasin/explore/DynamicRegister";
static const JNINativeMethod mMethods[] = {
        {"getMessage", "()Ljava/lang/String;", (void*)getString},
        {"getInt", "()I", (void*)getCount},
};

jint JNI_OnLoad(JavaVM* vm,void* reserved){
    JNIEnv* env = NULL;
    int r = (*vm)->GetEnv(vm,(void**) &env, JNI_VERSION_1_4);
    if( r != JNI_OK){
        return -1;
    }

    jclass mainActivityCls = (*env)->FindClass(env, mClassName);
    //计算注册方法数
    int count= sizeof(mMethods)/ sizeof(JNINativeMethod);
    r = (*env)->RegisterNatives(env,mainActivityCls,mMethods,count);
    if(r  != JNI_OK )
    {
        return -1;
    }
    return JNI_VERSION_1_4;
}

