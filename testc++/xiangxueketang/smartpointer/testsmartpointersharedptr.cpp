//
// Created by 王海龙 on 2021/4/24.
// 测试智能指针中的 shared_ptr  使用引用计数的方式来判断对象是否能够被回收 记数为0则回收
// shared_ptr 在栈中开辟空间
#include <iostream>
#include <memory>//智能指针头文件

using namespace std;

class Person {
public:
    char *name;
    int age;

    Person() {};

    virtual ~Person() {
        cout << "person 析构！！" << endl;
    }
};


int main() {
    Person *p = new Person();
    shared_ptr<Person> sptrP(p);

    return 0;
}




