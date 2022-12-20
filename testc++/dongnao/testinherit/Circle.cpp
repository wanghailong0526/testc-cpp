//
// Created by 王海龙 on 2022/9/8.
//

#include "Circle.h"
#include <iostream>

using std::cout;
using std::endl;

#define PI 3.14

Circle::Circle(int r) {
    this->r = r;
}


double Circle::size() {
    return PI * r * r;
}

void Circle::printSize() {
    cout << "Circle's size = " << size() << endl;
}


