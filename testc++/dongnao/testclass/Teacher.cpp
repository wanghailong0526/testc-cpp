//
// Created by 王海龙 on 2022/9/7.
//
#include "Teacher.h"
#include <iostream>

using std::cout;
using std::endl;

Teacher::Teacher() {
    cout << "调用无参构造函数" << endl;
}

//有参构造函数
//Teacher::Teacher(char *name, int age) {
//    this->age = age;
//    this->name = MALLOC(strlen(name), char);
//    strcpy(this->name, name);
//    cout << "调用有参构造函数" << endl;
//}
//有参构造函数 初始化参数列表写法
Teacher::Teacher(char *name, int age) : name(name), age(age) {
    cout << "调用有参构造函数" << endl;
}

//拷贝构造函数 深拷贝
Teacher::Teacher(const Teacher &t) {
    this->age = t.age;
    this->name = MALLOC(strlen(t.name), char);
    strcpy(this->name, t.name);
    cout << "调用拷贝构造函数" << endl;
}
//拷贝构造函数，浅拷贝 会有析构两次的问题，
//Teacher::Teacher(Teacher &t) {
//    this->age = t.age;
//    this->name = t.name;
//}

Teacher::~Teacher() {
    if (!name) {
        free(this->name);
        name = NULL;
    }
    cout << "调用析构函数" << endl;
}

void Teacher::setName(char *name) {
    this->name = name;
//    strcpy(this->name, name);
}

void Teacher::setAge(int age) {
    this->age = age;
}

char *Teacher::getName() {
    return this->name;
}

int Teacher::getAge() {
    return this->age;
}

//实现类的静态函数
void Teacher::count() {
    total++;
    cout << "total = " << total << endl;
}

void Teacher::print() const {
    cout << "调用常函数" << endl;

}

void Teacher::accessAny() {
    st.age = 30;
}
