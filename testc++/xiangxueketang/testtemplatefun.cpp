//
// Created by 王海龙 on 2021/4/6.
//测试模板函数
#include <iostream>

using namespace std;

template<typename T>
int add(T n1, T n2) {
    cout << "n1+n2=" << n1 + n2 << endl;
    return n1 + n2;
}

int main() {
    add(1, 2);
    add(0.5f, 0.4f);
    add(22.5L, 22.4L);
    return 0;
}


