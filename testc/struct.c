//
// Created by 王海龙 on 2022/8/26.
//
/**
 * 结构体 整体占用字节数为每个成员相加
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

struct stu {
    char *name;//姓名
    int age;//年龄
    float score;//成绩
    char gender;//性别 0_女 1_男

};
struct demo {
    char *name;//姓名
    int age;//年龄
    float score;//成绩
    char gender;//性别 0_女 1_男

} d1, d2 = {"kwg kwg ", 33, 98, 0};//只有d2初始化了，d1每个成员都没有值

int main() {
    struct stu stu1;
    stu1.age = 33;
//    strcpy(stu1.name, "王海龙");
    stu1.name = "王海龙 ";
    stu1.score = 98;
    stu1.gender = 1;
    printf("struct stu 占 %lu 个字节\n", sizeof(struct stu));
    printf("stu1 占 %lu 个字节\n", sizeof(stu1));
    printf("stu1 中 age 占 %lu 个字节\n", sizeof(stu1.age));
    printf("stu1 中 name 占 %lu 个字节\n", sizeof(stu1.name));
    printf("stu1 中 score 占 %lu 个字节\n", sizeof(stu1.score));
    printf("stu1 中 gender 占 %lu 个字节\n", sizeof(stu1.gender));
    printf("\n");

    printf("d2 中 name 为 %s:\n", d2.name);
    printf("d2 中 age 为 %d:\n", d2.age);
    printf("d2 中 score 为 %d:\n", d2.score);
    printf("d2 中 gender 为 %d:\n", d2.gender);

    printf("\n");

    printf("d1 中 name 为 %s:\n", d1.name);
    printf("d1 中 age 为 %d:\n", d1.age);
    printf("d1 中 score 为 %d:\n", d1.score);
    printf("d1 中 gender 为 %s:\n", d1.gender);

    return 0;

}
