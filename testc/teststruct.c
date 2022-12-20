//
// Created by 王海龙 on 2022/8/28.
//
/**
 * 结构体
 * 1.是一种构造数据类型，把不同的数据类型整合在一起成为一个自定义的类型
 * 2.匿名结构体相当于单例
 * 3.把一个结构体赋值给另一个结构体只能在声明时赋值
 * 4.-> 是 (*p) 的简写形式
 * 5.结构体变量的大小必须是最宽基本类型的整数陪，用于提高读取效率
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/****在构造结构体时声明变量****/
struct Man {
    char *name;
    int age;
} m4, m3 = {"hehehe", 17};//只有m3初始化了，m4是空值

struct Teacher {
    char *name;
};

/*******匿名结构体相当于单例******/
struct {
    struct Man man;
    struct Teacher t;
} human /*= {"*********", 29, "cjl"}*/;

/**********结构体的函数指针成员 void sayHello(char *)*********/
struct woman {
    int age;
    double weight;

    void (*sayHello)(char *);
};

void sayHello(char *text) {
//    printf(text);//也可以
    printf("%s\n", text);
}


void printStruct(struct Man *structMan) {
    printf("%s , %d \n", structMan->name, structMan->age);
}

int main(int argc, char **argv) {
    struct Man m1 = {"whl", 33};//结构体初始化
    struct Man m2 = m1;//使用已有结构体初始化要在声明时，m1改动不影响m2
    printf("Man1 name = %s ; age = %d \n", m1.name, m1.age);
    printf("Man2 name = %s ; age = %d \n", m2.name, m2.age);
    m1.name = "kwg kwg kwg ";
    m1.age = 11;
    printf("Man1 name = %s ; age = %d \n", m1.name, m1.age);
    printf("Man2 name = %s ; age = %d \n", m2.name, m2.age);
    printf("Man3 name = %s ; age = %d \n", m3.name, m3.age);
    printf("Man4 name = %s ; age = %d \n", m4.name, m4.age);//m4没有初始化 是空值


    human.man.name = "王海龙";
    human.man.age = 28;
    human.t.name = "cjl";
    printf("human.man.name = %s ; age = %d ; human.Teacher.name = %s\n", human.man.name, human.man.age, human.t.name);


    /*****************结构体指针*****************/
    struct Man *p = &m1;
    printf("%s , %d \n", (*p).name, (*p).age);
    printf("%s , %d \n", p->name, p->age);
    printStruct(p);

    /*****************结构体数组*****************/
    struct Man mans[] = {{"h", 11},
                         {"i", 12},
                         {"j", 13}};
    struct Man *pMans = mans;
    //打印方法1
    for (; pMans < mans + 3; ++pMans) {
        printf("%s, %d \n", pMans->name, pMans->age);
    }

    //打印方法2
    int i = 0;
    for (; i < sizeof(mans) / sizeof(struct Man); ++i) {
        printf("%s , %d \n", mans[i].name, mans[i].age);
    }

    /*****************结构体变量大小*****************/
    struct woman woman = {20, 100.87};
    printf("%#x , sizeof(woman) = %d , sizeof(double) = %d\n", &woman, sizeof(woman),
           sizeof(double));//输出: 0xb815e2f8 , sizeof(woman) = 16 , sizeof(double) = 8

    /*****************结构体与动态内存分配*****************/
    struct Man *pMan = (struct Man *) malloc(sizeof(struct Man) * 3);
    struct Man *p_man = pMan;
    p_man->name = "aa";
    p_man->age = 99;
    printf("动态内存分配 name = %s, age = %d \n", p_man->name, p_man->age);
    i = 1;
    for (; p_man < pMan + 3; ++p_man) {
        p_man->name = "bb";
        p_man->age = 10 + i++;
        printStruct(p_man);
    }
    if (!pMan) {
        free(pMan);
        pMan = NULL;
    }

    /**********结构体的函数指针成员 void sayHello(char *)*********/
    struct woman woman1 = {"哇哈哈", 20, sayHello};
    woman1.sayHello("你好呀！！！！！");


}

