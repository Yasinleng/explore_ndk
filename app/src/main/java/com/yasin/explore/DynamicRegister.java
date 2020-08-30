package com.yasin.explore;

/**
 * @Email: yasinleng@163.com
 * @Author: yasin
 */
public class DynamicRegister {

//    static {
//        System.loadLibrary("native-lib");
//    }

    public static native String getMessage();

    public static native int getInt();

    public static native String stringFromJNI();
}
