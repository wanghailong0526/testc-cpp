//
// Created by 王海龙 on 2022/8/28.
//
/**
 * 共用体(联合体)
 * 1.共用体任何时候只有一个成员存在
 * 2.共用体占用内存大小为最大成员所占字节数
 * 3.只有最后一次赋值有是有效的
 * 4.创建时不能初始化,要到声明时
 * 5.成员之间使用 ";"(分号)分隔
 *
 */
#include <stdio.h>

union MyValue {
    int x;//int x  = 0; //报错
    short y;
    double z;
};


int main(int argc, const char **argv) {
    union MyValue v;
    v.x = 5;
    v.y = 10;
    v.z = 100.23;//只有最后一次赋值有效
    printf("v.x = %d ; v.y = %d ; v.z = %lf \n", v.x, v.y, v.z);//输出: v.x = 1374389535 ; v.y = -31457 ; v.z = 100.230000
}

