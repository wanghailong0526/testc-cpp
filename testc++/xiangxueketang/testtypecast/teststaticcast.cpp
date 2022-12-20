//
// Created by 王海龙 on 2021/4/25.
// 测试 static_cast 指针
// static_cast 在编译期 转换后的类型看左边
#include <iostream>

using namespace std;

class Fuclass {
public:
    void show() {
        cout << "调用父类 show 方法" << endl;
    }
};

class Sonclass : public Fuclass {
public:
    void show() {
        cout << "调用子类 show 方法" << endl;
    }
};

int main() {
    int n = 8;
    void *pVoid = &n;
    int *num = static_cast<int *>(pVoid);
    cout << "转换后num=" << *num << endl;

    Fuclass *fu = new Fuclass();
    fu->show();

    //类型看左边 最终调用子类的show方法
    Sonclass *son = static_cast<Sonclass *>(fu);
    son->show();

    //回收对象 一定是 new 哪个对象回收哪个对象
    delete fu;


    return 0;
}

