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

extern "C" {

    JNIEXPORT jstring JNICALL NATIVE_CALL(sayHello)(JNIEnv *env, jobject obj) {
        jCls = env->GetObjectClass(obj);
        mEmptyCallback = NULL;
        mEmptyCallback = env->GetMethodID(jCls, "onCallback", "()V");

        env->CallVoidMethod(obj, mEmptyCallback);

        mStringCallback = NULL;
        mStringCallback = env->GetMethodID(jCls, "onCallback", "(Ljava/lang/String;)V");

        env->CallVoidMethod(obj, mStringCallback, env->NewStringUTF("Text from Callback"));

        return env->NewStringUTF("Hello from c++");
    }
}