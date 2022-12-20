//
// Created by 王海龙 on 2021/4/24.
// 测试 weak_ptr 在栈中开辟空间 没有引用记数

#include <iostream>
#include <memory>

using namespace std;

class Person1;//先声明Person1,下面再实现

class Person2;//先声明Person2,让Person1找到，否则报错

class Person1 {
public:
    weak_ptr<Person2> sptrP2;

    virtual ~Person1() {
        cout << "person1 析构" << endl;
    }
};

class Person2 {
public:
    weak_ptr<Person1> sptrP1;

    virtual ~Person2() {
        cout << "person2 析构" << endl;
    }
};

int main() {
    Person1 *p1 = new Person1();
    shared_ptr<Person1> sptrp1(p1);

    Person2 *p2 = new Person2();
    shared_ptr<Person2> sptrp2(p2);
    cout << "sptrp1 use count:" << sptrp1.use_count() << endl;
    cout << "sptrp2 use count:" << sptrp2.use_count() << endl;

    //下面两行代码使用拷贝构造方法使用引用记数不为0 从而无法回收
    p1->sptrP2 = sptrp2;
    p2->sptrP1 = sptrp1;
    cout << "sptrp1 use count:" << sptrp1.use_count() << endl;
    cout << "sptrp2 use count:" << sptrp2.use_count() << endl;


    return 0;
}

