//
// Created by 王海龙 on 2023/1/8.
//
/**
 * 实现 atoi 函数
 * 字符串数字 转 整型数字
 * @param str
 * @return int
 */

#include <stdio.h>
#include <math.h>


int myatoi(const char *&str) {
    const char *p = str;
    if (!p) {
        return -1;
    }
    int str_len = 0;//字符串长度
    while (*p++ != '\0') {
        str_len++;
    }
    printf("字符串长度 = %d\n", str_len);

    p = str;//因为计算 str 长度时 p 移动了指针 此处让 p 指向 str 第一个字符

    int num = 0;
    char temp = '0';
    int i = 0;
    for (; i < str_len; ++i) {
        temp = *p++;
        printf("temp char = %c\n", temp);
//        temp -= 0x30;
//        temp -= '0';
        temp -= 48;
        printf("temp 整型 = %d\n", temp);
        num += temp * int(pow(10, str_len - 1 - i));
        printf("num = %d\n", num);
    }
    return num;
}

int main() {
    const char *str_num = "54321";
    printf("输入字符串 = %s\n", str_num);
    printf("输出整型 = %d\n", myatoi(str_num));
}

