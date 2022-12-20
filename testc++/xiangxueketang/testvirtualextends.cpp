//
// Created by 王海龙 on 2021/4/5.
//测试虚继承，解决多继承环境下产生二义性问题, 多态是使用虚函数实现的，每个类都只有各自的共用部分
#include <iostream>

using namespace std;

class Object {
public:
    int number = 0;

    void show() {
        cout << "Object show函数执行了" << endl;
    }
};

class Ob1 : virtual public Object {
//public:
//    int number = 0;
};

class Ob2 : virtual public Object {
//public:
//    int number = 0;
};

class Son : public Ob1, public Ob2 {
};

int main() {
    Object object;
    Ob1 ob1;
    Ob2 ob2;
    Son son;

    object.number = 1;
    ob1.number = 2;
    ob2.number = 3;
    son.number = 4;

    object.show();
    ob1.show();
    ob2.show();
    son.show();

    cout << object.number << endl;
    cout << ob1.number << endl;
    cout << ob2.number << endl;
    cout << son.number << endl;

    return 0;
}