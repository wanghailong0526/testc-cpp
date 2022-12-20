//
// Created by 王海龙 on 2022/9/8.
//

#ifndef TESTC_CPP_CIRCLE_H
#define TESTC_CPP_CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
    int r;//半径
public:
    Circle(int r);

    double size() override;

    void printSize();
};


#endif //TESTC_CPP_CIRCLE_H
