# KotlinJNIExample
This projects shows configuring c++ files with cmake and write jni functions and callbacks using kotlin.

## Loading jni library

Use System.loadLibrary("example-lib") inside init block to load libraries, you can replace it with yours

 init {
        System.loadLibrary("example-lib")
    }

