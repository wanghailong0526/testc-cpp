//
// Created by 王海龙 on 2022/9/7.
//

#include "Point.h"
#include <iostream>

using std::cout;
using std::endl;

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

void Point::print() {
    cout << x << "," << y << endl;
}

Point Point::operator*(Point &p) {
    Point tmp(this->x * p.x, this->y * p.y);
    return tmp;
}




