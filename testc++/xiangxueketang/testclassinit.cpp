//
// Created by 王海龙 on 2021/4/5.
//测试类中包含对象的初始化方式
#include <iostream>

using namespace std;

class Person {
protected:
    string name;//string 内部是对 char* 的封装
    int age;
public:
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

//    Person(string name, int age) : name(name), age(age) {}
};

//课程类
class Course {
private:
    string courseName;

public:
    Course(string courseName) : courseName(courseName) {}

    string getCourseName() {
        return courseName;
    }
};

class Student : virtual public Person {
private:
    Course course;
public:
    Student(string name, int age, Course course) : Person(name, age), course(course) {
    }

    void print() {
        cout << "name:" << this->name << " age:" << this->age << " course:" << this->course.getCourseName() << endl;
    }
};

int main() {
    Course c("C++");
    Student s{"whl", 31, c};
    s.print();
    return 0;
}
