//
// Created by 王海龙 on 2022/8/26.
//
/**
 * 基本数据类型
 */
#include <stdio.h>
#include <stdlib.h>

struct demo {
    int a: 2;//位域操作 把一个字节中的二进位划分为几个不同的区域 占后2位
    int b: 4;//占后4位
    int c: 6;//占后6位
    /************上面整体位域占4字节***********/
//    int d;
} a;

struct S1 {
    int i: 8;
    char j: 4;
    int a: 4;
    double b;
} s1;
struct S2 {
    int i: 8;
    char j: 4;
    double b;
    int a: 4;
} s2;

int main() {
    int a = 1;//4字节
    short s = 2;//2字节
    long l = 3;//8字节
    float f = 1.1f;//4字节
    double d = 1.1;//8字节
    char c = 'd';//1字节
    printf("int 类型占 %lu 个字节\n", sizeof(int));
    printf("short 类型占 %lu 个字节\n", sizeof(short));
    printf("long 类型占 %lu 个字节\n", sizeof(long));
    printf("float 类型占 %lu 个字节\n", sizeof(float));
    printf("double 类型占 %lu 个字节\n", sizeof(double));
    printf("char 类型占 %lu 个字节\n", sizeof(char));
    printf("位域 整体占 %lu 个字节\n", sizeof(struct demo));

    //结构体
    printf("s1 struct 类型占 %lu 个字节\n", sizeof(s1)); // 输出16
    printf("s2 struct 类型占 %lu 个字节\n", sizeof(s2)); // 输出16


}

