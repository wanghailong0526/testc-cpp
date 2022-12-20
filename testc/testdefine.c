//
// Created by 王海龙 on 2022/8/30.
//
/**
 * #define
 * c语言执行流程
 * 1.预编译，为编译做准备，进行文本替换
 * 2.编译，生成 .obj 文件
 * 3.连接，将目标代码与 C 函数库连接合并，生成可执行文件
 * 4.执行
 *
 * #include ，告诉编译器有这样一个函数，连接器负责找到这个函数的实现
 * #define
 *  1.定义标识 #ifdef __cplusplus 表示支持 C++ 语法
 *  2.防止文件重复引入
 *      #ifndef AH
 *      #define AH
 *
 *      #include <stdio.h>
 *      void printfA(char * text);
 *
 *      #endif
 *    防止文件重复引入 #pragma once，放到文件最开头
 *  3.定义常量
 *  #define MAX 100
 *  4.定义宏函数
 *  #define JOW()
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/************测试宏函数************/
//此时必须在最右边加上"\"且该行"\"后不能再有任何字符，连注释部分都不能有，下面的每行最后的一定要是"\","\"后面加一个空格都会报错，更不能跟注释
#define MALLOC(n, type) \
((type*)malloc(n*sizeof(type))) //使用此函数为任意类型分配指定大小空间

void dn_com_jni_add() {
    printf("run %s\n", __FUNCTION__);
}

int dn_com_jni_add2(int a, int b) {
    printf("run %s\n", __FUNCTION__);
    return a + b;
}

void dn_com_jni_show() {
    printf("run %s\n", __FUNCTION__);
}
//NAME是参数
#define jni(NAME) dn_com_jni_##NAME();
#define JOW(NAME, N, M) dn_com_jni_##NAME(N,M);
//# 字符串化运算符 操作数必须是宏替换文本中的形参(把形参变成字符串)
// 例 #define printDBL( exp ) printf( #exp " = %f ", exp )
//    printDBL( 4 * atan(1.0));
// 展开为 printf( "4 * atan(1.0)" " = %f ", 4 * atan(1.0));
//## 的操作数必须是宏替换文本中的形参 至少有一个操作数是宏的形参 记号粘贴运算符 如果结果文本中还包含有宏名称，则预处理器会继续进行宏替换
#define LOG(LEVEL, FORMAT, ...) printf(LEVEL FORMAT,__VA_ARGS__);//编译器会合并紧邻的字符串字面量
//#define LOG(LEVEL, FORMAT, ...) printf(LEVEL); printf(FORMAT,__VA_ARGS__);
#define LOG_I(FORMAT, ...) LOG("INFO:",#FORMAT,__VA_ARGS__);
#define LOG_E(FORMAT, ...) LOG("ERROR:",#FORMAT,__VA_ARGS__);
#define LOG_W(FORMAT, ...) LOG("WARN:",#FORMAT,__VA_ARGS__);

/************测试宏函数************/

int main(int argc, const char **argv) {
/************测试宏函数************/
    char *p = NULL;
    p = MALLOC(5 + 1, char);
    strcat(p, "aaaaaa");
    printf("p=%s\n", p);
    free(p);
    jni(add);
    jni(show);
    int c = JOW(add2, 1, 2);
//    printf("%d\n", JOW(add2, 1, 2));//报错

    LOG_I("%s", "不是我干的！！！");

/************测试宏函数************/

}


