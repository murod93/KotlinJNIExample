//
// Created by MURODJON ABDUKHOLIKOV on 2020/04/10.
//

#include "example.h"

#include <jni.h>
#include <string>
#include <iostream>
#include <sstream>

// for native
#include <sys/types.h>
#include <android/log.h>
#include "android/asset_manager.h"
#include <android/asset_manager_jni.h>
#include <assert.h>
#include <cstring>

using namespace std;

//define a directive to simplify linking jni functions with c++
#define NATIVE_CALL(METHOD) Java_com_example_android_kotlinjniexample_Example_##METHOD

jclass jCls;
static jmethodID mEmptyCallback;
static jmethodID mStringCallback;
static jmethodID mNumCallback;

example exmp1;

extern "C" {

    JNIEXPORT void JNICALL NATIVE_CALL(sayHelloCallback)(JNIEnv *env, jobject obj){
        jCls = env->GetObjectClass(obj);
        mEmptyCallback = NULL;
        mEmptyCallback = env->GetMethodID(jCls, "onCallback", "()V");

        env->CallVoidMethod(obj, mEmptyCallback);

        mStringCallback = NULL;
        mStringCallback = env->GetMethodID(jCls, "onCallback", "(Ljava/lang/String;)V");

        env->CallVoidMethod(obj, mStringCallback, env->NewStringUTF(exmp1.test()));


        string test = exmp1.test();

        __android_log_print(ANDROID_LOG_DEBUG, "Example", "test printing android log");
    }

    JNIEXPORT void JNICALL NATIVE_CALL(runNumCallback)(JNIEnv *env, jobject obj){
        jCls = env->GetObjectClass(obj);

        mNumCallback = NULL;
        mNumCallback = env->GetMethodID(jCls, "onCallback", "(I)V");

        env->CallVoidMethod(obj, mNumCallback, 1);
    }

    JNIEXPORT jstring JNICALL NATIVE_CALL(sayHello)(JNIEnv *env, jobject obj) {
        return env->NewStringUTF("Hello from c++");
    }

    char* example::test(){
        return const_cast<char *>("Example test method");
    }

}