//
// Created by 王海龙 on 2022/9/7.
//
/**
 * 运算符重载
 * 1.定义
 * 1.文件中 类型 operator要重载的符号(&参数,&参数……)
 * 2.运算符重载在成员函数中
 */
#include "Point.h"

//运算符重载 + 号
Point operator+(Point &p1, Point &p2) {
    Point tmp(p1.x + p2.x, p1.y + p2.y);
    return tmp;
}

//运算符重载 - 号
Point operator-(Point &p1, Point &p2) {
    Point tmp(p1.x - p2.x, p1.y - p2.y);
    return tmp;
}

//z私有成员，私有成员通过友元函数进行运算符重载
Point operator/(Point &p1, Point &p2) {
    Point tmp(p1.z, p2.z);
}

int main(int argc, const char **argv) {
    Point p1(1, 1);
    Point p2(2, 2);
    Point p3 = p1 + p2;
    Point p4 = p3 - p1;
    p4.print();
    Point p5(4, 4);
    p5.print();
    Point p6(5, 5);
    p4 = p5 * p6;
    p4.print();
}

