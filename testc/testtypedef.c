//
// Created by 王海龙 on 2022/8/28.
//
/**
 * typedef
 * 1.取别名
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Man {
    char *name;
    int age;
};

/*****结构体别名****/
typedef struct Woman {
    char *name;
    int age;

    void (*sayHi)(char *);
} W, *Wp;//w 是结构体别名，*wp是结构体指针别名

void sayHi(char *text) {
    printf("%s\n", text);
}

typedef int jint;
typedef int Age;
typedef struct Man M;//结构体别名
typedef struct Man *Mp;//结构体指针别名
typedef W *Womanp;//给Woman结构体指针取名为Womanp


void reName(Womanp wp) {
    wp->name = "嘻嘻";
}

int main(int argc, char **argv) {
    W w = {"王海龙", 33};
    Wp wp = &w;;
    printf("%s , %d \n", w.name, w.age);
    printf("%s , %d \n", wp->name, wp->age);

    M m = {"陈加丽", 22};
    Mp mp = &m;
    printf("%s , %d \n", m.name, m.age);
    printf("%s , %d \n", mp->name, mp->age);

    W w2 = {"哈哈", 70, sayHi};
    Womanp womanp = &w2;
    womanp->sayHi("你好呀*****");
    printf("原来名字为: %s\n", womanp->name);
    reName(womanp);
    printf("修改名字为: %s\n", womanp->name);


}




