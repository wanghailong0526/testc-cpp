//
// Created by 王海龙 on 2022/9/13.
//
/**
 * 类型转换
 * 1.C中的类型转换 (type(expression))
 * 1.static_cast<type>(expression) 基本数据类型间的转换
 *  1.void指针转为其他类型指针
 *  2.基本数据类型之间的转换 如 int 转 char int 转 enum
 *  3.static_cast不能转换掉expression的const、volitale、或者__unaligned属性
 *  4.基类和子类之间指针或引用的转换
 *      1.上行转换（子类的指针或引用转换成基类表示）是安全的
 *      2.下行转换（把基类指针或引用转换成子类指针或引用），由于没有动态类型检查，所以是不安全的
 *  5.把任何类型的表达式转换成void类型
 *
 * 2.const_cast<type>(expression) 去const volatile 属性
 *      1.用来修改类型的 const 或 volatile（防止编译器对代码进行优化）属性
 *      2.const 或 volatile 修饰之外， type 和 expression 的类型是一样的
 *      3.常量指针被转化成非常量指针，并且仍然指向原来的对象
 *      4.常量引用被转换成非常量引用，并且仍然指向原来的对象
 *      5.常量对象被转换成非常量对象
 *
 * 3.dynamic_cast<type>(expression) 多态环境下父类和子类之间的转换
 *      1.基类和子类之间的转换
 *      2.必须要有虚函数
 *      3.相同基类不同子类之间转换为 NULL
 *
 * 4.reinterpret_cast<type>(expression)  不同类型的函数指针类型的转换
 *      1.仅仅重新解释类型，但没有进行二进制的转换
 *      2.转换的类型必须是一个指针、引用、算术类型、函数指针或者成员指针
 *      3. 在比特位级别上进行转换。
 *          1.把一个指针转换成一个整数，
 *          2.把一个整数转换成一个指针(先把一个指针转换成一个整数，在把该整数转换成原类型的指针，还可以得到原先的指针值)
 *          3.不能将非32bit的实例转成指针
 *      4.最普通的用途就是在函数指针类型之间进行转换
 *      5.很难保证移植性
 */
#include <iostream>

using namespace std;

typedef void (*Func_p)();//定义函数指针func
typedef int (*Func_i_p)(int a);//定义返回int类型的函数指针
int doSomething(int a) {
    return a;
}


int *getStream(void *p) {
    //将 void* 转换为 int*
    int *a = static_cast<int *>(p);
    *a = 5;
    return a;
}

struct RS {
    int i;
};

class Human {
public:
    virtual void print() {
        cout << "人类" << endl;
    }
};

class Man : public Human {
public:
    void print() override {
        cout << "男人" << endl;
    }
};

class Woman : public Human {
public:
    void print() override {
        cout << "女人" << endl;
    }
};

int main() {
/*********stati_cast***********/
    int a = 10;
    int *b = &a;
    double d = 0.0;
    //int 类型转换为 double类型
    d = static_cast<double>(a);
    cout << d << endl;
    int *p = getStream(b);
    cout << *p << endl;
/*********stati_cast***********/

/*********const_cast***********/
    const int c = 10;
    cout << "c的地址: " << &c << endl;
//    c = 20;//报错，const不能修改
    //常量指针转换为非常量指针
    int *e = const_cast<int *>(&c);
    *e = 5;//修改成功
    cout << "e 的地址为: " << e << endl;

    const struct RS rsa{};
//    rsa.i = 10;//报错
    //const_cast<struct RS &> 不加 & 会报错
    //Const_cast to 'struct RS', which is not age reference, pointer-to-object, or pointer-to-data-member
    RS rsb = const_cast<struct RS & >(rsa);
    rsb.i = 10;
    cout << "rsb.i = " << rsb.i << endl;
    cout << "rsa.i的地址为 " << &rsb.i << endl;
    cout << "rsb.i的地址为  " << &rsb.i << endl;

    //常量引用转换为非常量引用
    int &f = const_cast<int &>(c);
    f = 67;
    cout << "f = " << f << endl;
    cout << "f 的地址为: " << &f << endl;
/*********const_cast***********/

/*********dynamic_cast***********/
    Human *human;
    Man man;
    Woman *woman = dynamic_cast<Woman *>(&man);//相同基类，不同子类之间转换为 NULL
    if (woman) {
        cout << "woman 不为 NULL!" << endl;
        woman->print();
    } else {
        cout << "woman 为 NULL!" << endl;
    }
    //子类转换成父类
    human = dynamic_cast<Human *>(&man);
    human->print();//输出男人
    //子类转换成父类
    Woman woman1;
    human = dynamic_cast<Human *>(&woman1);
    human->print();//输出女人

    //父类转换成子类 在非多态环境下失败，要想成功必须父类引用指向子类对象
    Human human1;
    Man *man1 = dynamic_cast<Man *>(&human1);
    if (man1) {
        cout << "man1 不为 NULL!!" << endl;
        man1->print();//报错，子类不能转换为父类
    } else {
        cout << "man1 为 NULL!!" << endl;
    }

    //父类转换成子类 多态环境下,成功
    Human *human2 = &man;//父类引用指向子类对象
    Man *man2 = dynamic_cast<Man *>(human2);
    if (man2) {
        cout << "man2 不为 NULL!!" << endl;
        man2->print();//输出男人
    } else {
        cout << "man2 为 NULL!!" << endl;
    }
/*********dynamic_cast***********/

/*********reinterpret_cast***********/
    Func_p func[10];
    //存储
//    func[0] = &doSomething;//报错 类型不匹配
    int (*func_p_dosomething)(int a) = &doSomething;//定义函数指针
//    int h = func_p_dosomething(12);//函数指针调用
    //存储
    func[0] = reinterpret_cast<Func_p>(doSomething);//类型转换后成功
//    int g = func[0](15);//报错, func[0] 返回 void 类型，无法使用 int 类型接收
    //调用函数
    int g = reinterpret_cast<Func_i_p> (func[0])(15);//类型转换后 成功
    cout << g << endl;


/*********reinterpret_cast***********/

}

