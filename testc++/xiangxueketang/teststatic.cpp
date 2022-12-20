//
// Created by 王海龙 on 2021/4/4.
//TODO 测试 static 关键字
//
#include <iostream>

using namespace std;

class Dog {
public:
    char *name;
    int age;
//    static int id=5;//报错 原因是静态成员需要在类外初始化
    static int id;

    Dog() {}

    Dog(char *name, int age) : name(name), age(age) {
//        id = 9;//报错 静态成员不可以在类内使用这种方式初始化
    }

    void setName(char *name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

    static void setId(int id) {
        Dog::id = id;
    }

    static void update() {
//        下面方式运行报错
//        id = 9;
//        cout << "id= " << id << endl;
        cout << "调用了静态方法 update() " << endl;
    }

    void update2() {
        //        下面方式运行报错
        //        id = 9;
    }

    ~Dog() {
        cout << "调用了析构函数" << endl;
    }
};

int Dog::id = 13;//静态成员先实现再使用

int main(int argc, const char **argv) {

    Dog dog;
    Dog::update();
    dog.update2();
    dog.setAge(24);
    dog.setName("whl");
    Dog::setId(17);
    cout << "Dog1的name:" << dog.name << endl;
    cout << "Dog1的age:" << dog.age << endl;
    cout << "Dog1的id:" << dog.id << endl;

    Dog dog2;
    dog2.setAge(30);
    dog2.setName("wxxx");
    dog2.setId(19);
    cout << "Dog2的name:" << dog2.name << endl;
    cout << "Dog2的age:" << dog2.age << endl;
    cout << "Dog2的id:" << dog2.id << endl;

    cout << "Dog1的id:" << dog.id << endl;

    return 0;
}

