//
// Created by 王海龙 on 2022/11/29.
//
/**
 * typename 用作嵌套依赖类型
 * typename后面的字符串为一个类型名称，而不是成员函数或者成员变量
 * 如果前面没有typename，编译器没有任何办法知道T::LengthType是一个类型还是一个成员名称(静态数据成员或者静态函数)，
 * 所以编译不能够通过
 */
template<typename T>
class MyArray {
public:
    typedef int LengthType;
    LengthType length;

    void MyMethod(T myarr) {
        typedef typename T::LengthType LengthType;//若没有 typename 报错; typename T::LengthType 为一个整体代表一个类型名称
        LengthType length = myarr.length;//使用 Length 定义变量
    }
};



