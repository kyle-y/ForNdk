package com.yue.kyle.forndk;

/**
 * Created by yxb on 2018/3/13.
 */

public class TestJni1 {
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native int plus(int arg1, int arg2);
}
