//
// Created by 王海龙 on 2022/9/8.
//
/**
 * 模板函数(使用到了泛型)
 * 1.定义 template<typename T>
 *      void swap(T &A , T &b){}
 * 2.解决函数逻辑一样，但是函数参数类型不一样的问题
 * 3.屏蔽了类型,统一用 T 类型代替
 * 4.调用时可以指定传入是什么类型 swap<int>(A,b)
 * 5.T 类型会自动推导
 *
 */
#include <iostream>

using std::cout;
using std::endl;

void swapint(int &a, int &b) {
    int tmp = 0;
    tmp = a;
    a = b;
    b = tmp;
}

void swapfloat(float &a, float &b) {
    int tmp = 0;
    tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void swap(T &a, T &b) {
    T tmp = 0;
    tmp = a;
    a = b;
    b = tmp;
}


int main(int argc, const char **argv) {
    int a = 1;
    int b = 2;
    cout << "A = " << a << " b = " << b << endl;
    swap<int>(a, b);
    cout << "A = " << a << " b = " << b << endl;
    char x = 'a';
    char y = 'b';
    cout << "x = " << x << " y = " << y << endl;
    swap<char>(x, y);
    cout << "x = " << x << " y = " << y << endl;

}

