#include <jni.h>
#include <string>

extern "C" //因为引入了.h的C文件，所以要调用这个来执行
JNIEXPORT jstring JNICALL //jni宏定义，返回值类型（Linux下JNI函数声明可以省略这两个宏，建议保留）
Java_com_yue_kyle_forndk_TestJni1_stringFromJNI( //C++这里是Java_
        JNIEnv* env,    //提供jni环境变量指针，用于操作引入的函数
        jclass /* this */) { //TestJni1的实例对象，(stringFromJNI为static方法时是jclass，普通方法为jobject)
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str()); //C++ 这里使用一级指针
}

//C用法实例  （二级指针）
/*jstring Java_com_example_jni_MainActivity_stringFromC(JNIEnv* env,jobject thiz){
    return (*env)->NewStringUTF(env,"I am from C");
}*/

//如果要兼容C和C++，需要下面的代码
/*
#ifdef __cplusplus
extern "C" {
#endif

//一段代码

#ifdef __cplusplus
}
#endif
*/

extern "C"
jint Java_com_yue_kyle_forndk_TestJni1_plus(JNIEnv* env, jobject, jint a1, jint a2){
    return a1 + a2;
}
