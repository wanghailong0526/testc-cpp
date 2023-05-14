//
// Created by 王海龙 on 2023/5/13.
//
/**
 *
 */
#ifndef TESTC_CPP_STRING_H
#define TESTC_CPP_STRING_H

#include <iostream>
#include <cstring>

using std::string;

class String {
public:
    /**
     * 如果你使用了 char str，而不是 const char *str，
     * 则你只能向这个构造函数传递非 const 的 char 参数；
     * 当你定义为了 const char str 之后，你既可以传递 const char 的字符串，也可以传递 char * 的字符串。
     * 为什么呢？这是因为非 const 向 const 的转化是可以的，const 向非 const 的转化却是有风险的！
     *
     * @param str
     */
    String(const char *str = nullptr);//默认构造

    /**
     * 为什么要是 const 类型：
       因为只有 const 类型，才能接收 const 对象和非 const 对象参数。
       为什么要是引用类型：
       因为只有是引用类型，才能够规避递归使用拷贝构造的死循环问题：
       String(const String other);
       这个函数传递参数就会发生另一个参数传入，默认实参匹配调用拷贝构造，然后又调用这个函数，…，直到死循环。
       使用引用直接传对象实体进来，就不会在实参匹配时调用拷贝构造函数了
     * @param str
     */
    String(const String &str);//拷贝构造

    String(String &&other);//移动构造

    String &operator=(String &&other);//移动赋值运算符

    ~String();//析构
    String &operator=(const String &str);//赋值运算符

private:
    char *mData;
    int mSize;
};


#endif //TESTC_CPP_STRING_H
