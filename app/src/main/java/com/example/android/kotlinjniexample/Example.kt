package com.example.android.kotlinjniexample

import android.util.Log

/**
 * Created by murodjon on 2020/04/10
 */
class Example {
    private val TAG = "Example"

    lateinit var callback:ICallback
    constructor(callback:ICallback){
        this.callback = callback
    }

    external fun sayHello():String

    external fun sayHelloCallback()

    external fun runNumCallback()

    fun onCallback(num:Int){
        callback.onCallback(num)
    }

    fun onCallback() {
        Log.e(TAG, "callback from jni")
        callback.onCallback()
    }

    fun onCallback(msg:String){
        Log.e(TAG, msg)
        callback.onCallback(msg)
    }
    
    init {
        System.loadLibrary("example-lib")
    }

    interface ICallback{
        fun onCallback()
        fun onCallback(msg:String)
        fun onCallback(num:Int)
    }
}