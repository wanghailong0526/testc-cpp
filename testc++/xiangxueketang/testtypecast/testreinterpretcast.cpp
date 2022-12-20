//
// Created by 王海龙 on 2021/4/25.
// 测试强制类型转换 static_cast能做的事情，reinterpret_cast都能做到
#include <iostream>

using namespace std;

class Teacher {
public:
    void show() {
        cout << "调用了show方法" << endl;
    }
};

int main() {
    Teacher *whl = new Teacher();
    long whlol = reinterpret_cast<long>(whl);//将对象转换为long
    cout << "whl -> long = " << whlol << endl;

    Teacher *whl2 = reinterpret_cast<Teacher *>(whlol);//将long转换为对象
    whl2->show();

    printf("whl的地址=%p\n", whl);
    printf("whl2的地址=%p\n", whl2);

    //指针存放的地址一样，但是指针有自己存放自己的地址
    printf("whl的地址=%p\n", &whl);
    printf("whl2的地址=%p\n", &whl2);


    return 0;
}


