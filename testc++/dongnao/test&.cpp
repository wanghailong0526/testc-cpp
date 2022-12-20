//
// Created by 王海龙 on 2022/9/6.
//
/**
 * 引用
 * 1.定义 int &A = b;
 * 2.变量的别名 指针是变量的地址
 * 3.作为函数的参数或返回值
 * 4.指针的引用代替二级指针
 * 5.引用必须初始化
 * 6.引用初始化不能为NULL值 int &A = NULL; 报错
 * 7.单纯给变量起别名没有意义，引用在作为函数参数时，不产生变量副本
 * 8.引用可以直接操作变量，指针要通过取值(*p) 间接操作变量可读性差
 * 9.不能返回局部变量的引用(方法结束后，变量回收了) 所以用引用代替二级指针
 * 10.因为引用不能为空，所以作为函数参数时在函数内部一定不为空
 * 11.如果函数参数为指针，指针可以传空，需要在方法内部做判断
 *
 * 常引用
 * 1.定义 const int &A = b;
 * 2.作为函数参数时，不能修改a的值，能修改指向的地址
 *
 * 常引用字面量
 * 1.const int &e = 70;
 *
 * 指针常量
 * 1.定义 int *const A=&b;
 * 2.指针的常量,不允许修改指针的指向,能修改指针指向的内容
 * 3.A = &c; 报错
 * 4.*A = 3; 通过
 *
 * 常量指针
 * 1.定义 const int *A = &b;
 * 2.指向常量的指针，不允许修改指针指向的内容，能修改指针的地址
 * 3.*A = 3; 报错
 * 4.A = &c; 通过
 *
 * 函数参数
 * 1.有默认值，void show(int A = 10){ cout << A << endl;}
 * 2.如果有多个参数，第一个参数有默认值，后面的参数都要写默认值
 *
 *
 * 可变参数
 * 1.必须是参数列表的最后一个
 * 2.遍历
 *      1.va_list ap;//可变参数的指针
 *      2.va_start(ap,A);//指定参数列表中最后一个固定参数为a
 *      3.va_arg(ap,i);//读取一个参数
 *      4.va_end(ap);//结束
 *
 *
 */
#include <iostream>
#include <stdarg.h>//可变参数 c语言也有这个头文件

using std::cout;
using std::endl;
using namespace std;
//定义宏函数
#define MALLOC(n, type) (type*)malloc((n)*sizeof(type))

struct Teacher {
    int age;
    char *name;
};

//引用作为函数参数
void myPrint(Teacher &t) {
    cout << t.age << t.name << endl;
}

//指针作为函数参数
void myPrint2(Teacher *t) {
    cout << t->age << t->name << endl;
}

/**
 * 参数是二级指针生成Teacher 对象
 * @param t
 */
void getTeacher(Teacher **t) {
    Teacher *tmp = MALLOC(1, struct Teacher);//生成Teacher对象¬
    tmp->age = 10;
    strcpy(tmp->name, "whl");//"whl"字面量就是const char * 类型
    *t = tmp;
}

/**
 * 指针的引用代替二级指针生成Teacher对象
 * @param p
 */
void getTeacher(Teacher *&p) {
    p = MALLOC(1, struct Teacher);
    p->age = 33;
    strcpy(p->name, "hhh");
}

/**
 * 常引用作为函数参数时，不能修改值
 * @param a
 */
void getNum(const int &a) {
    cout << "常引用 A = " << a << endl;
//    A = 2;//报错 不能修改a的值
}

/**
 * 可变参数的遍历
 * @return
 */
void HH(int a, ...) {
    //方法1
    va_list args_p;//可变参数指针
//    va_start(args_p, A);//指定a为最后一个固定参数
//    int i = va_arg(args_p, int);
//    int e = va_arg(args_p, int);
//    int b = va_arg(args_p, int);
//    cout << A << endl;
//    cout << i << endl;
//    cout << e << endl;
//    cout << b << endl;
//    va_end(args_p);//结束

    //方法2
    int i = 0;
    va_start(args_p, a);
    for (; i < a; ++i) {
        cout << va_arg(args_p, int) << endl;
    }
    va_end(args_p);
}

int main() {
    struct Teacher t = {33, "whl"};
    myPrint(t);
    myPrint2(&t);
    struct Teacher *t2 = NULL;
//    getTeacher(t2);//引用的方式 //一级指针的引用代替二级指针方式 如果初始化为null,报错
//    cout << "ts name = " << t2->name << " age = " << t2->age << endl;
//    struct Teacher *t3;//一级指针
//    getTeacher(&t3);
//    cout << "ts name = " << t3->name << " age = " << t3->age << endl;

    //指针常量，不能修改指针的指向，能修改指针指向的值
    int a = 1, b = 2;
    int *const c = &a;
    //c = &b;//报错
    *c = a;//通过

    //常量指针，不能修改指针指向的内容，能修改指针的指向
    const int *p = &b;
//    *p = 3;//报错
    p = &a;//通过

//    const int c;//报错,常量必须初始化
//    int &c;//报错，引用必须初始化
//    int &c = NULL;//报错，引用不能为NULL

    //常引用
    const int &d = a;
    getNum(a);
    //常引用字面量
    const int &e = 70;

    //可变参数
    HH(3, 2, 'c', 4);

}

