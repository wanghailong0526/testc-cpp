//
// Created by 王海龙 on 2022/8/26.
//

#ifndef UNTITLED_ARR_H
#define UNTITLED_ARR_H

#define GET_ARRAY_LENGTH(arr) sizeof(arr)/sizeof(arr[0])//计算数组长度
/**
 * #include < > 引用编译器的类库路径里面的头文件。
 * #include " " 引用当前程序目录的相对路径中的头文件，如果在程序目录没有找到引用的头文件则到编译器的类库路径的目录下找该头文件。
 */
#include <stdio.h>
#include <stdlib.h>

void printArr(int len, int *arr) {
    printf("\n");
    int *p = arr;

    /******使用for******/
    int i = 0;
    for (; i < len; ++i) {
        printf("arr[%d] = %d ; 地址为 %#x\n", i, *p, p);
        p++;
    }

    /*******使用while********/
//    while (len > 0) {
//        printf("arr: %d\n", *p);
//        p++;
//        len--;
//    }
}

#endif //UNTITLED_ARR_H

