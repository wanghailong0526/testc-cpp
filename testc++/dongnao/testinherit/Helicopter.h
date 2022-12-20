//
// Created by 王海龙 on 2022/9/8.
//

#ifndef TESTC_CPP_HELICOPTER_H
#define TESTC_CPP_HELICOPTER_H
/**
 * 直升飞机
 */
#include "Plane.h"

class Helicopter : public Plane {
public:
    //virtual 、 final 、 override 都可以实现多态
    virtual void fly() /*override*/;

    //final 或 override
    virtual void land() /*override*/;
};


#endif //TESTC_CPP_HELICOPTER_H
