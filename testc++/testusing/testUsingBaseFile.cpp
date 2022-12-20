//
// Created by 王海龙 on 2022/11/26.
//
/**
 * using
 * 在子类中引用基类的私有成员，使子类对象可以调用父类的私有成员
 * 只是引用，不参与参数的指定
 *
 */
#include <iostream>

class T5Base {
public:
    T5Base() : value(55) {
        std::cout << "调用 T5Base 无参构造方法！！" << std::endl;
    }

    virtual ~T5Base() {
        std::cout << "调用 T5Base 析构方法！！" << std::endl;
    }

    /**
     * 拷贝构造方法
     * @param base
     */
    T5Base(T5Base &base) {
        std::cout << "调用 T5Base 拷贝构造方法！！" << std::endl;
    }

    T5Base &operator=(const T5Base &base) {
        std::cout << "调用赋值运算符" << std::endl;
    }

    void test1() {
        std::cout << "base test1" << std::endl;
    }

    void setValue(int value) {
        this->value = value;
    }

    void printVlaue() {
        printMsg();
    }

protected:
    int value;
    int age;

    void printMsg() {
        std::cout << "base value = " << value << std::endl;
    }
};

class T5Son : private T5Base {
public:
    T5Son() {
        std::cout << "调用 T5Son 无参构造方法！！" << std::endl;
    }

    ~T5Son() {
        std::cout << "调用 T5Son 析构方法！！" << std::endl;
    }

    using T5Base::value;

    using T5Base::test1;
    using T5Base::printMsg;

    void printValue() {
        std::cout << "Son value is " << value << std::endl;
    }

    void test3() {
        test1();
    }
};

int main() {
    T5Base base;
    T5Base base2(base);//调用默认的拷贝构造函数 浅拷贝
    base2.test1();
    T5Son son;
    T5Son son2 = son;
    son2.value = 5;
    printf("son2.value = %d\n", son2.value);
    printf("son.value = %d\n", son.value);
    base.setValue(20);
    base.printVlaue();
    son.printValue();
    son.test3();
    printf("son.value=%d\n", son.value);
    son.test1();
    son.printMsg();

}

