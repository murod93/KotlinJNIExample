# KotlinJNIExample
This projects shows configuring c++ files with cmake and write jni functions and callbacks using kotlin.

### Add ```CMakeLists.txt``` file to the module in which you implement C++, and configure path in the file and add to ```build.gradle```

#### build.gradle

```

android {
    ...

    defaultConfig {
        ...

        splits {
            abi {
                enable true
                reset()
                include 'armeabi-v7a', 'arm64-v8a', 'x86', 'x86_64'
                universalApk true
            }
        }

        externalNativeBuild {
            cmake {
                arguments '-DANDROID_STL=c++_shared'
                '-DANDROID_CPP_FEATURES=rtti exceptions std=c++11'
            }
        }
    }

    sourceSets {
        main {
            jni.srcDirs = []
            jniLibs.srcDirs = [
                    'src/main/cpp',
                    'src/main/jni',
                    'src/main/jniLibs/'
            ]
        }
    }

    externalNativeBuild {
        cmake {
            path 'CMakeLists.txt'
        }
    }
 ...
}

...

```
#### CMakeLists.txt
```
cmake_minimum_required(VERSION 3.4.1)

# Global
set(CPP_ROOT src/main/cpp)

find_library( log-lib log)
find_library(android-lib android)

# Verifier
add_library(
        example-lib
        SHARED
        ${CPP_ROOT}/example.cpp
)

target_link_libraries(
        example-lib
        ${android-lib}
        ${log-lib}
)
```

### Loading jni library

Use System.loadLibrary("example-lib") inside init block to load libraries, you can replace it with yours
```kotlin
 init {
        System.loadLibrary("example-lib")
    }
```
### Writing native method

The external(kotlin) or native(java) keyword is applied to a method to indicate that the method is implemented in native code using JNI (Java Native Interface). native or external is a modifier applicable only for methods and we can’t apply it anywhere else. The methods which are implemented in C, C++ are called as native methods or foreign methods.
```
    external fun sayHello():String
```

### jni Callback
```
    fun onCallback() {
        Log.e(TAG, "callback from jni")
    }
```
