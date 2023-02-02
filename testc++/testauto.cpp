//
// Created by 王海龙 on 2023/1/14.
//
/**
 * auto 推导规则
 */
 /**
  * 1.编译期类型推导
auto 推导规则
1.无法推导出引用
2.推导引用类型时直接替换为引用的具体类型
例：
int a =0;
const int &b  = a ;
auto c = b; // c 为 int  类型 相当于 auto c = a const 被去掉了

3.有引用符号，会忽略修饰指针的 const
int a = 0;
const int * const b=&a;
auto &p = b; 相当于 auto const int * p  = b;

4.没有引用符号，const 都会保留
int a =  1;
const int* const b = &a;
auto &c = b; // c 的类型为const int const &


  */
#include <stdio.h>

int main() {
    int a = 97;
    int b = 98;
    const int *const p = &a;
    auto s = p;// s 的类型为 const int * 常量指针 可以修改指针指向的内存地址，不能修改值
    printf("s 的值为 %d\n", *s);
    s = &b;
    printf("s 的值为 %d\n", *s);
//    *s = 77;//报错
    const int d = 0;
    auto e = d;
    e = 3;//成功
    int i =0;
    printf("++++++i 的值为 %d\n", (++i)++);




}

