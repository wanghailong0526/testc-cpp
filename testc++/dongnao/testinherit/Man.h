//
// Created by 王海龙 on 2022/9/7.
//

#ifndef TESTC_CPP_MAN_H
#define TESTC_CPP_MAN_H

#include "Human.h"


class Man : public Human {
private:
    char *brother;
public:

    Man(char *name, int age);
    ~Man();

    void say();


};


#endif //TESTC_CPP_MAN_H
