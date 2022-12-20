//
// Created by 王海龙 on 2021/4/6.
//
// 补充点： 继承关系的时候，构造函数和析构函数 的顺序问题

#include <iostream>

using namespace std;

class Person {
public:
    string name;

    Person(string name) : name(name) {cout << "Person构造函数" << endl;}

    ~Person()  {cout << "Person析构函数" << endl;}

    virtual void test() {
        cout << "父 test..." << endl;
    }
};

class Student : public Person {
public:
    string name;

    Student(string name) : Person(name) {
        cout << "Student构造函数" << endl;

        // Person::test();
    }

    ~Student()  {cout << "Student析构函数" << endl;}

    void test() {
        cout << "子 test..." << endl;
    }
};

int main() {
    Student student("Derry");
    // Person构造函数
    // Student构造函数
    // Student析构函数
    // Person析构函数

    Student student1("A");
    student1.test();

    return 0;
}

