//
// Created by 王海龙 on 2022/9/7.
//
/**
 * 继承
 * 1.public 继承方式，最终调用的是父类方法
 * 2.向父类构造方法传参,
 *   1.如果子类没有构造方法，需要在子类构造方法中向父类构造方法传参 看Man.cpp中的构造方法
 *   2.构造函数与析构函数的顺序
 *      1.先调用父类构造，再调用子类构造
 *      2.先调用子类析构，再调用父类析构
 *   3.子类覆盖父类方法后想要调用父类方法或修改父类成员变量值 可以这样做 子类对象.父类::父类方法 man.Human::say()
 *
 * 多继承(java单继承 c++多继承)
 * 1.多继承二义性 3个类分别是 A,a1,a2,a1都有name成员, a1,a2继承于A, b继承于a1,a2,此时调用b.name 不知道是使用谁的name
 *   1.虚继承，继承时使用virtual关键字 不同路径继承来的相同成员只有一份拷贝，解决不明确的问题
 *      1.class a1 : virtual public A
 *      2.class a2 : virtual public A
 *      3.class b : public a1, public a2
 * 2.虚函数
 *   1.用在多态中(多态解决程序扩展性) 动态多态(程序在执行过程中决定调用哪个方法 如:方法的覆盖) 静态多态(如:方法的重载)
 *      1.多态发生的条件
 *          1.继承
 *          2.父类引用指向子类对象
 *          3.方法重载或覆盖
 * 3.纯虚函数(抽象类)
 *      1.定义: virtual 返回类型 方法名 =0; virtual void show()=0;)
 *      2.抽象类不能实例化对象
 *      3.当类里只要有一个纯虚函数，这个类就是抽象类
 *      4.子类继承抽象类，必须实现纯虚函数，否则不能实例化对象，子类也变成了抽象类
 *      5.抽象类里可以有非纯虚函数
 *
 * 4.全纯虚函数(接口)
 *      1.一个类里全部都是纯虚函数，这个类就是全纯虚函数，相当于接口
 *      2.全纯虚函数里不能有其它非纯虚函数
 *
 * //继承的访问修饰
//基类中      继承方式             子类中        子类外
//public     ＆ public继承 = > public          可以访问
//public     ＆ protected继承 = > protected    无法访问
//public     ＆ private继承 = > private        无法访问
//
//protected  ＆ public继承 = > protected       无法访问
//protected  ＆ protected继承 = > protected    无法访问
//protected  ＆ private继承 = > private        无法访问
//
//private    ＆ public继承 = > 子类无权访问       无法访问
//private    ＆ protected继承 = > 子类无权访问    无法访问
//private    ＆ private继承 = > 子类无权访问      无法访问

 多态
 1.静态多态
    1.方法重载
    2.模板
    3.函数指针，通过传入函数指针的回调实现多态
 2.动态多态
    1.方法覆盖
    2.c++17中的 std::variant 和 std::visit

 */

#include "Human.h"
#include "Man.h"
#include <iostream>
#include <variant>
#include <typeinfo>

using namespace std;

//多继承问题
class A {
public:
    char *name;
};

class A1 : virtual public A {

};

class A2 : virtual public A {

};

class B : public A1, public A2 {

};

/*******************虚函数指针调用虚函数表中的函数*******************/
class Base {
public:
    virtual void print() {
        cout << "base print" << endl;
    }

    virtual void func() {
        cout << "base func" << endl;
    }

    function<void()> fun;
};

class Son : public Base {
public:
    void print() override {
        cout << "son print" << endl;
    }

    void func() override {
        cout << "son func" << endl;
    }

    function<void()> fun;
};
/*******************虚函数指针调用虚函数表中的函数*******************/

#include "Plane.h"
#include "Helicopter.h"

//可以传飞机及飞机的子类
void flyAndLand(Plane &p) {
    p.fly();
    p.land();
}

#include "Circle.h"

typedef void (*fun)();//定义函数指针 fun

int main(int argc, const char **argv) {
    //public 继承方式，最终调用的是父类方法
//    Man man;
//    man.say();
//    Human human;
//    human.say();
//    Human human1 = man;//子类对象初始化父类对象
//    human1.say();//调用父类方法
//    Human *human2 = &man;//父类型的引用或指针指向子类对象
//    human2->say();//调用父类方法

    //向父类构造方法传参 构造与析构顺序
//    Man man("whl", 33);
//    man.print();

    //父类与子类方法重名 都有say方法，子类会覆盖父类方法
//    Man man1("whl", 11);
//    man1.Human::say();//子类调用父类方法
//    man1.Human::age = 10;
//    man1.print();
//    man1.Human::age = 100;
//    man1.print();
//    man1.say();//调用子类方法

    //多继承的二义性
//    B b;
// //    b.name;//报错,不使用虚继承 不知道使用哪个name
//    //使用虚继承 不同路径继承来的同名成员只有一份拷贝，解决不明确的问题
//    b.name;

    //虚函数 解决多态问题
//    Plane plane;
//    flyAndLand(plane);//
//    Helicopter helicopter;
//    flyAndLand(helicopter);

//    //纯虚函数(抽象类)
//    Circle c(5);
//    c.printSize();
////    Shape s;//报错，抽象类不能实例化对象

/*********************使用虚函数指针调用虚函数表中的函数***********************/
    //虚函数指针在对象首位，虚函数指针指向虚函数表
//    Son s;//这样也可以
    Base *s = new Son();//这是第二种方式
    long b_add = *((long *) s);//把对象转换成 long 类型的地址
    fun p_fun = (fun) (*(long *) b_add);
    p_fun();//打印 son print
    p_fun = (fun) (*(((long *) b_add) + 1));
    p_fun();//打印 son func
/*********************使用虚函数指针调用虚函数表中的函数***********************/


    /***********函数指针实现多态    通过传入的函数指针回调实现多态************/
    Base b;
    Son s1;
    b.fun = bind(&Son::print, s1);
    b.fun();
    /***********函数指针实现多态    通过传入的函数指针回调实现多态************/

    /***********c++17 std::variant(可变类型)实现多态************/
    variant<int, float> v, w;
    v = 12;
    int i = get<int>(v);
    cout << "i = " << i << endl;
//    get<3>(v);//报错 没有这个下标
    w = get<int>(v);//通过数据类型获取当前存储的值
    w = get<0>(v);//通过下标获取当前存储的值
    try {
        float f = get<float>(v);//报错,没有存储 float 类型
        cout << "f = " << f << endl;
    } catch (bad_variant_access &e) {
        cout << e.what() << endl;
    }
    w = v;
    auto a = get<0>(w);
    cout << "a type =" << typeid(a).name() << endl;//输出类型名称，int_i float_f

    /***********c++17 std::variant实现多态************/

}