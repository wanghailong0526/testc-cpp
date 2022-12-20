//
// Created by 王海龙 on 2022/9/6.
//
/**
 * 类
 * 拷贝构造函数 类(const 类 &变量) Student(const Student &s)
 * 1.浅拷贝，拷贝的是指针的地址(类默认的拷贝构造函数)
 * 2.深拷贝，拷贝的是指针指向的值
 * 3.调用时机
 *    1.声明时赋值 Student s1 = s;  Student s2(s);
 *    2.作为参数传递  实参给形参赋值 show(Student s)
 *    3.作为函数返回值返回，给变量初始化赋值 Student s3 = Func_p(s1);
 */
#include "Teacher.h"
#include <iostream>

using namespace std;

//Teacher 类的友元函数，访问私有成员
void modify(Teacher *t, int age) {
    t->age = age;
}

//类的大小8字节对齐 不计算静态成员变量、函数的大小，有对齐，B类大小为20,对齐后是24
//指针占4个字节
//虚函数因为存在一个虚函数表，需要4个字节
//一个空类占1个字节，若类里有成员则计算所有成员的大小
class A {

};

class B {
public:
    int i;
    int j;
    int k;
    double x;

    void myprintf(int a) {
        cout << "打印" << endl;
    }
};

//类的静态属性初始化
int Teacher::total = 1;


int main() {
    char name[] = {'w', 'h', 'l', '\0'};//不加 \0 会输出乱码
//    Teacher t1;//调用无参构造函数
//    Teacher t(name, 33);
//    cout << t.getName() << t.getAge() << endl;
//    Teacher t2(t);
//    Teacher t3 = t;

    //c++ new创建 delete删除 不能重复调用delete
//    Teacher *t4 = new Teacher();//调用无参构造函数
//    delete t4;
//    Teacher *t5 = new Teacher(name, 22);//调用有参构造函数
//    delete t5;
    //C语言 malloc创建内存 free释放 不能重复调用free 不调用构造和析构函数
//    Teacher *t6 = MALLOC(1, Teacher);
//    t6->setAge(33);
//    t6->setName(name);
//    cout << t6->getName() << endl;
//    cout << t6->getAge() << endl;
//    free(t6);

    //数组的创建与释放
//    int *p = MALLOC(3, int);
//    p[0] = 9;
//    cout << p[0] << endl;
//    if (!p) {
//        free(p);
//        p = NULL;
//    }
//    int *p2 = new int[10];
//    p2[0] = 10;
//    cout << p2[0] << endl;
//    if (!p2) {
//        delete[] p2;
//        p2 = NULL;
//    }

    //操作类的静态成员和方法 可以通过类名::访问 也可以通过对象访问
//    Teacher t;
//    t.count();
//    Teacher::total = 4;
//    t.count();
//    Teacher::count();
//    Teacher *t2 = new Teacher(name, 11);
//    (*t2).count();

    //类的大小 B类有对齐本来是20 对齐后是24，
    //C/C++内存分区 栈，堆，全局区(静态变量存在此处)，常量区(字符串)，程序代码区
//    cout << sizeof(A) << endl;
//    cout << sizeof(B) << endl;
//    cout << sizeof(double) << endl;

    //常量对象只能调用常函数,不能调用常函数以外的函数
//    const Teacher t7(name, 88);
//    t7.print();
//    Teacher t8(name, 33);
//    t8.print();

    //友元函数
//    Teacher *t = new Teacher(name, 11);
//    cout << t->getAge() << endl;
//    modify(t, 33);
//    cout << t->getAge() << endl;

    //友元类，可以访问所有属性

}

