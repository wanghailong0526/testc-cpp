//
// Created by 王海龙 on 2022/11/20.
//
/**
 * 绑定右值的右值引用，其变量本身是左值
 */
#include <iostream>

int fun(int &a) {
    std::cout << "in fun(int &)" << std::endl;
}

int fun(int &&a) {
    std::cout << "in fun(int &&)" << std::endl;
}

int main() {
    int a = 1;
    int &&b = 1;//此时 b 为左值
    int *p = &b;
    b = 2;
    fun(b);
    std::cout << "b 的地址为：" << p << std::endl;

    return 0;
}