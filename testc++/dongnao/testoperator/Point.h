//
// Created by 王海龙 on 2022/9/7.
//

#ifndef TESTC_CPP_POINT_H
#define TESTC_CPP_POINT_H


class Point {
    //私有成员，可以通过友元函数进行运算符重载
    friend Point operator/(Point &p1, Point &p2);

private:
    int z;
public:
    int x;
    int y;
public:
    Point(int x = 0, int y = 0);

    Point operator*(Point &p);

    void print();
};


#endif //TESTC_CPP_POINT_H
