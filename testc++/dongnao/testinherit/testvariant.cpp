//
// Created by 王海龙 on 2022/10/8.
//
#include <iostream>
#include <variant>

using namespace std;

/*******************std::variant 实现动态多态*******************/
class Base {
public:
    void print() const {
        cout << "base print" << endl;
    }

    void func() {
        cout << "base func" << endl;
    }
};

class Son : public Base {
public:
    void print() const {
        cout << "son print" << endl;
    }

    void func() {
        cout << "son func" << endl;
    }
};

/********************使用函数对象作为访问器******************/
struct call_print {
    void operator()(const Base &b) {
        b.print();
    }

    void operator()(const Son &s) {
        s.print();
    }
};

int main() {
    Base b;
    variant<Base, Son> v = Son();
    visit(call_print(), v);
    v = Base();
    visit(call_print(), v);
}

