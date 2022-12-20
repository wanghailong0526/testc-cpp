//
// Created by 王海龙 on 2022/9/7.
//

#ifndef TESTC_CPP_HUMAN_H
#define TESTC_CPP_HUMAN_H


class Human {
public:
    char *name;
    int age;
public:
    Human(char *name, int age);

    ~Human();

    void say();

    void print();
};


#endif //TESTC_CPP_HUMAN_H
