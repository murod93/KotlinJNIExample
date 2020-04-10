package com.example.android.kotlinjniexample

import android.util.Log

/**
 * Created by murodjon on 2020/04/10
 */
class Example {
    private val TAG = "Example"

    external fun sayHello():String

    fun onCallback() {
        Log.e(TAG, "callback from jni")
    }

    fun onCallback(msg:String){
        Log.e(TAG, msg)
    }
    
    init {
        System.loadLibrary("example-lib")
    }
}