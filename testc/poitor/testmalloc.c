//
// Created by 王海龙 on 2022/8/27.
//
#include "arr.h"

/**
 * 动态分配内存
 * malloc(字节)  free(p) 释放内存 配对使用
 * int *p = (int *)malloc(1024 * 1024 *10 * sizeof(int));//这种写法 c/c++ 都支持 如果不强制类型转换 在C++中不支持
 * 1.分配40M内存
 * 2.p是数组的首地址也是数组名称
 *
 * calloc( length,sizeof(int) ) 与malloc一样，会自动计算内存大小，free(p)释放内存
 *
 * realloc 重新分配内存 使用malloc分配的内存不够用，
 *   重新分配内存的两种情况：
 *   缩小，缩小的那一部分数据会丢失
 *   扩大，（连续的）
 *  1.如果当前内存段后面有需要的内存空间，直接扩展这段内存空间，realloc返回原指针
 *  2.如果当前内存段后面的空闲字节不够，那么就使用堆中的第一个能够满足这一要求的内存块，将目前的数据复制到新的位置，并将原来的数据库释放掉，返回新的内存地址
 *  3.如果申请失败，返回 NULL，原来的指针仍然有效
 *  int *p2 = realloc( p , (len+5)*sizeof(int) );
 *  if(p2==NULL) printf("重新分配失败")
 *
 *
 *  释放
 *  if(p!=NULL) { free(p); p=null }
 *
 *  **********动态内存分配注意事项*************
 *  1.不能多次释放
 *  2.释放完后给指针设置为 null，标致释放完成
 *  3.注意内存泄漏，重新 malloc 要先 free 再 malloc
 */

int main(int argc, char **argv) {
    int len = 5;
//    int *p = malloc(len * sizeof(int));
    int *p = calloc(len, sizeof(int));//calloc 和 malloc一样

    int i = 0;
    for (; i < len; ++i) {
        p[i] = rand() % 100;
        printf("动态分配内存结果p[%d] = %d ; p[%d]的地址为%#x\n", i, p[i], i, &p[i]);
    }
    printArr(len, p);

    /**********即使 p2 分配成功也不能现在释放 p 否则报错 在要确定不使用 p 时释放*********/
    int add = 5;
    int *p2 = realloc(p, sizeof(int) * (len + add));//重新分配内存
    if (p2 == NULL) {
        printf("重新分配内存失败");//p依然有效
    }
    i = 5;
    for (; i < len + add; ++i) {
        p2[i] = rand() % 200;
        printf("重新分配内存结果p[%d] = %d ; p[%d]的地址为%#x\n", i, p2[i], i, &p2[i]);
    }

    printArr(len + add, p2);

    if (p != NULL) {
        free(p);
        p = NULL;
    }
    if (p2 != NULL) {
        free(p2);
        p2 = NULL;
    }
}



















