//
// Created by 王海龙 on 2022/9/7.
//

#include "Man.h"
#include <iostream>

using std::cout;
using std::endl;

//给父类构造方法传参
Man::Man(char *name, int age) : Human(name, age) {
    cout << "Man 构造！" << endl;
}

Man::~Man() {
    cout << "Man 析构！" << endl;
}

void Man::say() {
    cout << "Man say hello!" << endl;
}


