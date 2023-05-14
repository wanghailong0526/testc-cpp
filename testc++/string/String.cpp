//
// Created by 王海龙 on 2023/5/13.
//
#include "String.h"


/**
 * 默认构造
 * @param str
 */
String::String(const char *str) {
    if (str == nullptr) {
        mData = new char[1];
        *mData = '\0';
        mSize = 0;
    } else {
        mSize = strlen(str);
        mData = new char[mSize + 1];
        strcpy(mData, str);
    }
    std::cout << "调用默认构造" << std::endl;
}

/**
 * 拷贝构造
 * @param str
 */
String::String(const String &str) {
    mSize = strlen(str.mData);
    mData = new char[mSize + 1];
    strcpy(mData, str.mData);
    std::cout << "调用拷贝构造" << std::endl;
}

/**
 * 赋值运算符
 * this 是本对象的地址
 * @param str
 * @return
 */
String &String::operator=(const String &str) {
    if (this != &str) {
        if (!mData) delete[] mData;
        mSize = strlen(str.mData);
        mData = new char[mSize + 1];
        strcpy(mData, str.mData);
    }
    std::cout << "调用赋值运算符" << std::endl;
    return *this;
}

/**
 * 移动构造
 */
String::String(String &&other) {
    mData = other.mData;
    mSize = other.mSize;
    other.mData = nullptr;
    other.mSize = 0;
    std::cout << "调用移动构造" << std::endl;
}

/**
 * 移动赋值运算符
 */
String &String::operator=(String &&other) {
    if (this != &other) {
        delete[] mData;
        mData = other.mData;
        mSize = other.mSize;
        other.mData = nullptr;
        other.mSize = 0;
    }
    std::cout << "调用移动赋值运算符" << std::endl;
    return *this;
}

String::~String() {
    delete[] mData;
    mData = nullptr;
    std::cout << "调用析构" << std::endl;
}