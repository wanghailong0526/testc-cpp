//
// Created by 王海龙 on 2022/9/6.
//
/**
 * 1.c++的命名空间 类似java中的包
 * 2.:: 为访问修饰符
 * 3.结构体成员有private public属性和方法，不能被继承
 * 4.类成员有private public属性和方法，能被继承
 * 5.三目运算符可以成为左值 (A>b?A:b)=30
 *
 */
#include <iostream>
#include <limits>
//第一种写法
//using namespace std
//第二种写法
using std::cout;
using std::endl;
using namespace std;
//第三种写法 在代码里 std::cout

//定义namespace
namespace nsp_A {
    int a;
    struct Student {
        int age;
        char *name;
        int gender;
    };
}

namespace nsp_B {
    int a;
}
/**
 * 结构体
 */
struct Teacher {
private :
    int age;
    char *name;
    short gender;
public:
    void setAge(int age) {
        Teacher::age = age;
    }

    void setName(char *name) {
        this->name = name;
    }

    void setGender(int gender) {
        Teacher::gender = gender;
    }

public:
    int getAge() {
        return age;
    }

    char *getName() {
        return name;
    }

    int getGneder() {
        return gender;
    }

};

#define PI 3.14

/**
 *类
 */
class Circle {
private :
    double r;//半径
    double d;//直径
public:
    void setR(double r) {
        this->r = r;
    }

    void setD(double d) {
        Circle::d = d;
    }

    double getSizeR() {
        return PI * r * r;
    }

    double getLengthR() {
        return PI * r * 2;
    }

    double getLengthD() {
        return PI * d;
    }
};

void swap(int *a, int *b) {
    int c = 0;
    c = *a;
    *a = *b;
    *b = c;
}

/**
 * 引用方式交换两数
 * @param a
 * @param b
 */
void swap2(int &a, int &b) {
    int c = 0;
    c = a;
    a = b;
    b = c;
}

int main(int argc, const char **argv) {
    nsp_A::a = 10;
    nsp_B::a = 20;
    cout << "nsp_A:A = " << nsp_A::a << endl;
    cout << "nsp_B:A = " << nsp_B::a << endl;
    //命名空间中使用struct
    struct nsp_A::Student stu = {33, "whl", 1};
    cout << "姓名:" << stu.name << "\n年龄:" << stu.age << "\n性别:" << (stu.gender == 1 ? "男" : "女") << endl;

    Teacher teacher;
    teacher.setAge(33);
    teacher.setName("whl");
    teacher.setGender(1);
    cout << "姓名:" << teacher.getName() << "\n年龄:" << teacher.getAge() << "\n性别:"
         << (teacher.getGneder() == 1 ? "男" : "女") << endl;

    Circle circle;
    circle.setR(54.1l);
    cout << "圆的周长为: " << circle.getLengthR() << " 面积为：" << circle.getSizeR() << endl;
    bool siSingle = -1;//非0为真
    short sh = 1;
    char c = 'c';
    int i = 1;
    long l = 1;
    float f = 1.1f;
    double d = 1.2;//默认是double
    wchar_t ch = 'c';

    if (-1) {
        cout << "真" << endl;
    } else {
        cout << "假" << endl;
    }

    cout << "type: \t\t" << "************size**************" << endl;
    cout << "bool: \t\t" << "所占字节数：" << sizeof(bool);
    cout << "\t最大值：" << (numeric_limits<bool>::max)();
    cout << "\t\t最小值：" << (numeric_limits<bool>::min)() << endl;
    cout << "char: \t\t" << "所占字节数：" << sizeof(char);
    cout << "\t最大值：" << (numeric_limits<char>::max)();
    cout << "\t\t最小值：" << (numeric_limits<char>::min)() << endl;
    cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);
    cout << "\t最大值：" << (numeric_limits<signed char>::max)();
    cout << "\t\t最小值：" << (numeric_limits<signed char>::min)() << endl;
    cout << "unsigned char: \t" << "所占字节数：" << sizeof(unsigned char);
    cout << "\t最大值：" << (numeric_limits<unsigned char>::max)();
    cout << "\t\t最小值：" << (numeric_limits<unsigned char>::min)() << endl;
    cout << "wchar_t: \t" << "所占字节数：" << sizeof(wchar_t);
    cout << "\t最大值：" << (numeric_limits<wchar_t>::max)();
    cout << "\t\t最小值：" << (numeric_limits<wchar_t>::min)() << endl;
    cout << "short: \t\t" << "所占字节数：" << sizeof(short);
    cout << "\t最大值：" << (numeric_limits<short>::max)();
    cout << "\t\t最小值：" << (numeric_limits<short>::min)() << endl;
    cout << "int: \t\t" << "所占字节数：" << sizeof(int);
    cout << "\t最大值：" << (numeric_limits<int>::max)();
    cout << "\t最小值：" << (numeric_limits<int>::min)() << endl;
    cout << "unsigned: \t" << "所占字节数：" << sizeof(unsigned);
    cout << "\t最大值：" << (numeric_limits<unsigned>::max)();
    cout << "\t最小值：" << (numeric_limits<unsigned>::min)() << endl;
    cout << "long: \t\t" << "所占字节数：" << sizeof(long);
    cout << "\t最大值：" << (numeric_limits<long>::max)();
    cout << "\t最小值：" << (numeric_limits<long>::min)() << endl;
    cout << "unsigned long: \t" << "所占字节数：" << sizeof(unsigned long);
    cout << "\t最大值：" << (numeric_limits<unsigned long>::max)();
    cout << "\t最小值：" << (numeric_limits<unsigned long>::min)() << endl;
    cout << "double: \t" << "所占字节数：" << sizeof(double);
    cout << "\t最大值：" << (numeric_limits<double>::max)();
    cout << "\t最小值：" << (numeric_limits<double>::min)() << endl;
    cout << "long double: \t" << "所占字节数：" << sizeof(long double);
    cout << "\t最大值：" << (numeric_limits<long double>::max)();
    cout << "\t最小值：" << (numeric_limits<long double>::min)() << endl;
    cout << "float: \t\t" << "所占字节数：" << sizeof(float);
    cout << "\t最大值：" << (numeric_limits<float>::max)();
    cout << "\t最小值：" << (numeric_limits<float>::min)() << endl;
    cout << "size_t: \t" << "所占字节数：" << sizeof(size_t);
    cout << "\t最大值：" << (numeric_limits<size_t>::max)();
    cout << "\t最小值：" << (numeric_limits<size_t>::min)() << endl;
    cout << "string: \t" << "所占字节数：" << sizeof(string) << endl;
    // << "\t最大值：" << (numeric_limits<string>::max)() << "\t最小值：" << (numeric_limits<string>::min)() << endl;
    cout << "type: \t\t" << "************size**************" << endl;


    /**
     * 引用
     * 用在变量声明上
     */
    int x = 10;
    int z = 50;
    int &b = x;
    cout << b << endl;
    int *y = &b;
    cout << y << endl;
    //非引用方式交换两数
    cout << "交换前 x =" << x << " z=" << z << endl;
    swap(&x, &z);
    cout << "交换后 x =" << x << " z=" << z << endl;
    cout << "交换前 x =" << x << " z=" << z << endl;
    swap2(x, z);
    cout << "交换后 x =" << x << " z=" << z << endl;


}

