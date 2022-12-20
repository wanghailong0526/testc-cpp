//
// Created by 王海龙 on 2022/8/26.
//
/**
 * 指针
 * 指针存储的是变量的内存地址
 * 指针的类型决定了在内存中读取到什么位置
 *
 * #include < > 引用的是编译器的类库路径里面的头文件。
 * #include " " 引用的是你程序目录的相对路径中的头文件，如果在程序目录没有找到引用的头文件则到编译器的类库路径的目录下找该头文件。
 */
#include "arr.h"


void change(int *p);//通过指针改变变量的值

void poitoroperation();//指针操作
void printArr(int len, int arr[]);//打印数组

int main() {
    int i = 10;
    int *p = &i;
    printf(" i 的值为 %d\n", i);
    printf(" p 的地址为 %#x\n", p);

    *p = 20;//间接赋值
    printf(" *p 的值为 %d\n", *p);
    printf(" i 的值为 %d\n", i);

    int **pp = &p;
    printf(" pp 的地址为 %#x\n", pp);
    printf(" pp 的值为 %#x\n", **pp);

    change(&i);
    printf(" i 的值为 %d\n", i);
    printf(" i 的地址为 %#x\n", &i);

    /*************空指针************/
    int *q;
    q = NULL;
    printf(" q 的地址为 %#x\n", q);
//    printf(" q 的值为 %d\n", *q);//无法打印
    printf("\n");
    printf("\n");

    /********指针对数组的操作********/
    poitoroperation();
}

void change(int *p) {
    *p = 100;
}


/**
 * 数组的首元素是数组的首地址 &arr[0]
 * 数组名是数组的首地址 arr
 * 定义指针指向数组后，指针的地址是数组的首地址 int *p = arr;
 * p++ 表示指针向后移动sizeof(数据类型)个字节，代表指向数组的下一个位置 p-- 表示指向数组的上个位置
 */
void poitoroperation() {
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr;
    printf("p 的地址为 %#x\n", p);
    printf("arr 的地址为 %#x\n", arr);
    printf("arr 的地址为 %#x\n", &arr);
    printf("arr 的第一个元素地址为 %#x\n", &arr[0]);
    printf("arr个数为 %d\n", GET_ARRAY_LENGTH(arr));//GET_ARRAY_LENGTH 定义在头文件里

    //通过指印为数组赋值
    int stus[5];
    int *p_stus = stus;
    int i = 0;
    for (; p_stus < stus + 5; ++p_stus) {
        *p_stus = i;
        ++i;
    }
    printArr(GET_ARRAY_LENGTH(stus), stus);
}

