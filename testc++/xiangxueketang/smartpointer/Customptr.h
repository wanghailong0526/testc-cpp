//
// Created by 王海龙 on 2021/4/24.
// 自定义引用记数的智能指针，在引用记数为0时释放对象

#ifndef UNTITLED_CUSTOMPTR_H
#define UNTITLED_CUSTOMPTR_H

#pragma once //在头文件最开始的地方加入此指令保证头文件被编译一次

#include <iostream>
#include <memory>

using namespace std;

template<typename T>//定义模板让智能指针对任何对象都适用
class Ptr<T> {
private:
    T obj;//对象
    int *count; //引用记数
public:
    //第一种情况 此种方式是通过 new Ptr 智能指针因为没有传入要引用记数的对象，所以 obj = 0
    //例:
    // Ptr<Person> ptr();
    Ptr() {
        count = new int(1);
        obj = 0;
    }

    //第二种情况 通过带参数的构造方法传入对象
    //例:
    //Person p = new Person();
    // Ptr<Person> ptr(p);
    Ptr(T *t) : obj(t) {
        count = new int(1);
    }

    //第三种情况 通过拷贝构造函数赋值
    //例：
    //Person p = new Person();
    //Ptr<Person> ptr(p);
    //Ptr<Person> ptr2 = ptr;//调用拷贝构造函数
    //如果是下面这样就不会调用拷贝构造函数
    //Person p = new Person();
    //Ptr<Person> ptr(p);
    //Ptr<Person> ptr2;//
    // ptr2 = ptr;//这样不会调用拷贝构造函数
    Ptr(const Ptr<T> &p) {
        cout << "拷贝构造函数" << endl;
        ++(*p.count);
        obj = p.obj;
        count = p.count;//最终 p.count = this.count == 2
    }

    //自定义=号运算符
    //例: ptr2 = ptr
    //需要先清空之前的Ptr内容
    Ptr<T> &operator=(const Ptr<T> &p) {
        cout << "=号运算符重载" << endl;
        ++(*p.count);
        if (--(*count) == 0) {
            if (obj) {
                delete obj;
            }
            delete count;
        }

        obj = p.obj;
        count = p.count;
        return *this;//运算符重载返回结果
    }


    //析构函数
    virtual ~Ptr() {
        if (--(*count) == 0) {//引用记数为0释放obj
            if (obj) {
                delete obj;
            }
            //归零
            delete count;
            obj = 0;
            count = 0;
        }
    }

    //返回引用记数的数值
    int use_count() {
        return *this->count;
    }

};


#endif //UNTITLED_CUSTOMPTR_H
