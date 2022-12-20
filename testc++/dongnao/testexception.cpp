//
// Created by 王海龙 on 2022/9/12.
//
/**
 * C++异常
 * 1.抛出异常使用 throw
 * 2.根据抛出的异常类型，进入到相应的 catch 块中
 * 3.catch 任意类型 使用 ...
 * 4.声明函数抛出的异常类型
 *      void Func_p(int A,int b,)throw(类型){}
 * 5.自定义异常 catch(Exception & e) 要catch一个引用，避免生成对象副本  不要抛出指针，throw new Exception 还要delete,避免内存泄露
 * 6.throw(const char *) instead of noexcept(false)
 * 7.标准异常 out_of_range("越界") invalid_argument("参数不合法")
 * 8.类中类异常
 */
#include <iostream>
#include <exception>
#include <stdexcept>

using std::cout;
using std::endl;
using std::exception;

struct MyException : public exception {
    const char *what() const throw() {
        return "my Exception";
    }
};

//struct 可以被继承
class A : public MyException {
};

//自定义异常
class NullPointerException : public exception {
private:
    char *msg;
public:
    NullPointerException(char *msg) {
        this->msg = msg;
    }

    ~NullPointerException() override {
        msg = nullptr;
    }

    const char *what() noexcept(false) {
        return msg;
    }
};

//类中类异常
class Err {
public:
    class MyException : public exception {
    private:
        char *msg;
    public:
        MyException(char *msg) {
            this->msg = msg;
        }

        const char *what() const throw() {
            return msg;
        }
    };
};

void myFunc() throw(MyException) {
    throw MyException();
}

void myFunc2() throw(A) {
    throw A();
}

void func(int a, int b) throw(const char *) {
    if (b == 0) {
        throw "除数为0!";
    }
}

void func2(int a, int b) noexcept(false) {
    if (b == 0) {
        throw std::out_of_range("越界");
    }
    if (b == 1) {
        throw std::invalid_argument("参数非法");
    }
    if (b == 2) {
        throw NullPointerException("空指针");
    }
    if (b == 3) {
        throw "异常了";
    }
}


int main() {
    int a = 0;
    try {
        throw 9.8;
    } catch (int) {
        cout << "int类型异常" << endl;
    } catch (char) {
        cout << "char类型异常" << endl;
    } catch (...) {//catch任意类型
        cout << "未知异常" << endl;
    }

    try {
        Func_p(1, 0);
    } catch (const char *str) {
        cout << str << endl;
    } catch (const char *str) {
        cout << str << endl;
    }

    try {
        myFunc();
    } catch (MyException &e) {//catch引用 避免生成 对象副本
        cout << e.what() << endl;
    }
    try {
        myFunc2();
    } catch (A &e) {
        e.what();
    }

    try {
        func2(1, 1);
    } catch (const char *str) {
        cout << str << endl;
    } catch (std::out_of_range &outOfRange) {
        cout << outOfRange.what() << endl;
    } catch (std::invalid_argument &invalidArgument) {
        cout << invalidArgument.what() << endl;
    } catch (NullPointerException &e) {
        cout << e.what() << endl;
    }

    try {
        throw Err::MyException("出问题了！");
    } catch (Err::MyException &e) {
        cout << e.what() << endl;
    }


}

