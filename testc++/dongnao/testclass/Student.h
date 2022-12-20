//
// Created by 王海龙 on 2022/9/7.
//

//#ifndef TESTC_CPP_STUDENT_H
//#define TESTC_CPP_STUDENT_H
//
//#endif //TESTC_CPP_STUDENT_H
#pragma once

#include "Teacher.h"

class Student {
    //友元类 可以访问Student的所有成员
    friend class Teacher;

private:
    char *name;
    int age;
public:
    char *getName() const;

    void setName(char *name);

    int getAge() const;

    void setAge(int age);
};