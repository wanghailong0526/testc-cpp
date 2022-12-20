//
// Created by 王海龙 on 2022/8/28.
//
/**
 * 枚举
 * 1.列举所有情况
 * 2.限定值的范围
 * 3.成员之间用 ","(逗号)分隔
 */
#include <stdio.h>

enum Day {
    Monday = 0,
    Tuesday = 1,
    Wednesday = 2,
    Thursday = 3,
    Friday = 4,
    Saturday = 5,
    Sunday = 6
};

int main(int argc, const char **argv) {
    enum Day day = Monday;
    printf("monday 地址为 %#x ; day = %d\n",&day,day.);
}
