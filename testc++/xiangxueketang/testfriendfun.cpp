//
// Created by 王海龙 on 2021/4/5.
//测试友元函数
#include <iostream>

using namespace std;

class Persion {
private:
    char *name;
    int age;

public:
//    Persion(int age) : age(age) {}//可以使用下面的另一种写法
    Persion(int age) {
        this->age = age;
    }

    void setAge(int age) {
        this->age = age;
    }

    int getAge() {
        return age;
    }

    //定义友元函数,修改私有变量.只声明无实现
    friend void updateAge(Persion &persion, int age);
};

void updateAge(Persion &persion, int age) {
    persion.age = age;
}

int main() {
    Persion p = Persion(9);
    cout << "p的年龄是: " << p.getAge() << endl;
    updateAge(p, 13);
    cout << "更新p的年龄是: " << p.getAge() << endl;

    Persion p2 = Persion(10);
    cout << "p2的年龄是" << p2.getAge() << endl;
    updateAge(p2,20);
    cout << "更新p2的年龄是" << p2.getAge() << endl;
    p2.setAge(30);
    cout << "更新p2的年龄是" << p2.getAge() << endl;



}
