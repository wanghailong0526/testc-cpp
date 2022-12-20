//
// Created by 王海龙 on 2022/8/26.
//
/**
 * 函数指针
 * 函数名就是函数指针
 * 定义: 函数返回类型(*函数名)(参数)=已有函数名
 */
#include <stdio.h>
#include "arr.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

void message(int a, int b) {
    printf("A = %d , b = %d \n", a, b);
}

int add(int a, int b) {
    printf("回调函数执行\n");
    return a + b;
}

int printn(int a) {
    printf("A = %d \n", a);
}

void msg(int (*fun)(int a, int b), int m, int n) {
    printf("执行msg代码\n");
    printf("执行回调函数代码\n");

    int r = fun(m, n);
    printf("回调函数执行结果 %d \n", r);
}

int *getMinNumber(int len, int arr[]) {
    int *p = &arr[0];
    while (len > 1) {
        if (arr[--len] < *p) {
            p = &arr[len];
        }
    }
    return p;
}

int main() {
    int (*p)(int a) =printn;
    p(1);

    void (*m)(int a, int b) =message;
    m(1, 2);

    printf("message 函数的地址为%#x\n", message);
    printf("message 函数的地址为%#X\n", &message);

    msg(add, 1, 2);

    /**********随机生成10个100以内的数，找出最小值*********/
    srand((unsigned) time(NULL));
    int arr[10];
    int i = 0;
    while (i < 10) {
        arr[i] = rand() % 100;
        ++i;
    }
    printArr(GET_ARRAY_LENGTH(arr), arr);
    int *r = getMinNumber(GET_ARRAY_LENGTH(arr), arr);
    printf("最小值地址为: %#X   最小值为 %d", r, *r);
//    printf("最小值地址为: %#X   最小值为 %d", getMinNumber(GET_ARRAY_LENGTH(arr), arr),
//           *getMinNumber(GET_ARRAY_LENGTH(arr), arr));
}

