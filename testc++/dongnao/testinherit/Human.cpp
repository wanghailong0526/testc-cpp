//
// Created by 王海龙 on 2022/9/7.
//

#include "Human.h"
#include <iostream>

using std::cout;
using std::endl;

Human::Human(char *name, int age) {
    this->name = name;
    this->age = age;
    cout << "Humman 构造！！" << endl;
}
Human::~Human() {
    cout << "Humman 析构！！" << endl;
}

void Human::say() {
    cout << "Human say hello!！" << endl;
}

void Human::print() {
    cout << "name = " << name << " age = " << age << endl;
}
