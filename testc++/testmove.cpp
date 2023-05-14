//
// Created by 王海龙 on 2022/11/29.
//
#include <cstddef>
#include <algorithm>
#include <iostream>

/**
 * move 移动语义
 * 移动构造函数
 *  1.先将自己的资源恢复默认
 *  2.获取传入对象的资源
 *  3.传入对象的资源恢复默认
 *
 * 移动赋值运算符
 *  1.传入的对象与自己是不是同一个对象，如果是同一个对象不要操作
 *  2.删除自己的资源
 *  3.获取传入对象的资源
 *  4.传入对象的资源恢复默认
 *
 * explicit:防止构造函数隐式初始化
 */
class BigObj {

private:
    size_t length_;
    int *data_;

public:
    /**
     * 构造函数
     * @param length
     */
    explicit BigObj(size_t length) : length_(length), data_(new int[length]) {
        std::cout << "调用构造函数" << std::endl;
    }

    /**
     * 析构函数
     */
    ~BigObj() {
        if (data_) {
            delete data_;
            data_ = nullptr;
        }
        length_ = 0;
        std::cout << "调用析构函数" << std::endl;
    }

    /**
     * 拷贝构造函数
     * @param obj
     */
    BigObj(const BigObj &obj) : length_(obj.length_), data_(new int[obj.length_]) {
        std::copy(obj.data_, obj.data_ + obj.length_, data_);
        std::cout << "调用拷贝构造函数" << std::endl;
    }

    /**
     * 赋值运算符
     * @param obj
     * @return
     */
    BigObj &operator=(const BigObj &obj) {
        if (this != &obj) {
            delete[] data_;
            data_ = new int[obj.length_];
            length_ = obj.length_;
            std::copy(obj.data_, obj.data_ + obj.length_, data_);
        }
        std::cout << "调用赋值运算符" << std::endl;
        return *this;
    }

    /**
     * 移动构造函数
     * 重点在于对自己及传入对象的初始化操作
     * @param obj
     */
    BigObj(BigObj &&obj) : data_(nullptr), length_(0) {
        data_ = obj.data_;
        length_ = obj.length_;

        obj.data_ = nullptr;
        obj.length_ = 0;
        std::cout << "调用移动构造函数" << std::endl;
    }

    /**
     * 移动赋值运算符
     * @param obj
     * @return
     */
    BigObj &operator=(BigObj &&obj) {
        if (this != &obj) {//如果不是同一个对象
            delete[] data_;

            data_ = obj.data_;
            length_ = obj.length_;

            obj.data_ = nullptr;
            obj.length_ = 0;
        }
        std::cout << "调用移动赋值运算符" << std::endl;
        return *this;
    }

    size_t getlength() {
        return length_;
    }
};

template<typename T>
void printMsg(T obj) {
    std::cout << obj << std::endl;
}

int main() {
//    BigObj obj = 1;//报错 如果构造函数不加 explicit 关键字就通过，加了之后防止构造函数隐式初始化
    BigObj obj(2);//调用构造函数
    BigObj obj2 = obj;//调用拷贝构造函数
    BigObj obj3(obj2);//调用拷贝构造函数
    printMsg(obj2.getlength());//输出 2
    BigObj obj4 = std::move(obj2);//调用移动构造函数
    printMsg(obj4.getlength());//输出 2
    BigObj obj5(std::move(obj2));//调用移动构造函数
    printMsg(obj2.getlength());//输出 0
    obj = obj2;//调用赋值运算符
    printMsg(obj.getlength());//输出 0
    obj = std::move(obj2);//调用移动赋值运算符
}
