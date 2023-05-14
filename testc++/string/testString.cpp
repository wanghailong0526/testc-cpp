//
// Created by 王海龙 on 2023/5/14.
//
#include "String.h"
#include <iostream>
int main(){
    {
        // 测试：默认构造
        String s1;

        // 测试：传参构造
        String s2("hello world");

        // 测试：拷贝构造
        String s3(s1);

        // 测试：移动构造
        String s4(std::move(s3));

        // 测试：拷贝赋值
        String s5;
        s5 = s4;

        // 测试：移动赋值
        String s6;
        s6 = std::move(s5);
    }

}

