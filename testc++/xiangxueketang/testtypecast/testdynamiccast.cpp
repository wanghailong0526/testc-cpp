//
// Created by 王海龙 on 2021/4/25.
// 测试动态类型转换 在运行时  动态转换需要父类方法必须为虚函数
#include <iostream>

using namespace std;

class Fuclass {
public:
    virtual void show() {
        cout << "调用父类show方法" << endl;
    }
};

class Son : public Fuclass {
public:
    void show() {
        cout << "调用子类show方法" << endl;
    }
};

int main() {
    Fuclass *fuclass = new Son();
    (*fuclass).show();
    Son *son = dynamic_cast<Son *> (fuclass);//如果父类方法不是虚函数，报错：父类方法不是多态的
    son->show();

    Fuclass *fuclass1 = new Fuclass();
//    Son *son1 = dynamic_cast<Fuclass * >(fuclass1);//报错:父类不能转换为子类

    return 0;
}
