//
// Created by 王海龙 on 2021/4/5.
//测试继承
#include <iostream>

using namespace std;

class Person {
public:
    char *name;
    int age;

    Person(char *name, int age) : name(name), age(age) {
        cout << "父类构造函数" << endl;
    }

    void print() {
        cout << "name:" << this->name << " age:" << this->age << endl;
    }
};

class Student : public Person {
private:
    char *course;
public:
    Student(char *name, int age, char *course) : Person(name, age), course(course) {
        cout << "子类构造函数" << endl;
    }

    char *getCourse() {
        return this->course;
    }

    void operator-(const Student &s) {
        this->age -= s.age;
    }
};

int main() {
    Student s("hh", 20, "English");
    s.print();
    cout << "s的姓名:" << s.name << " s的年龄:" << s.age << " s的课程:" << s.getCourse() << endl;

    Student s2{"xx", 30, "Chinese"};
    cout << "s2的姓名:" << s.name << " s2的年龄:" << s.age << " s2的课程:" << s.getCourse() << endl;

    s2 - s;
    cout << "s2的姓名:" << s2.name << " s2的年龄:" << s2.age << " s2的课程:" << s2.getCourse() << endl;


    return 0;
}

