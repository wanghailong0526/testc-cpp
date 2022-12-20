//
// Created by 王海龙 on 2022/9/7.
//

//#ifndef TESTC_CPP_TEACHER_H
//#define TESTC_CPP_TEACHER_H
//
//#endif //TESTC_CPP_TEACHER_H
#pragma once

#include <cstdlib>
#include <cstring>
#include "Student.h"

#define MALLOC(n, type) (type*)malloc((n)*sizeof(type))

class Teacher {
    //友元函数 可以访问类的私有成员
    friend void modify(Teacher *t, int age);

private:
    char *name;
    int age;
    Student st;

public:
    //类的静态属性 要在类外初始化
    static int total;

    //无参构造
    Teacher();

    //有参构造
    Teacher(char *name, int age);

    //析构函数，释放空间
    ~Teacher();

    //拷贝构造函数(深拷贝)
    Teacher(const Teacher &t);

    void setName(char *name);

    void setAge(int age);

    char *getName();

    int getAge();

    //类的静态函数
    static void count();

    //this 的修饰 const Teacher* const this 即不能改变指针的值，也不能改变指针指向的内容
    //常函数 修饰this,常量对象只能调用常函数,不能调用常函数以外的函数,普通对象都可以调用
    void print() const;

    //访问友元的所有属性和方法
    void accessAny();
};
