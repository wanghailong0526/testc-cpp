//
// Created by 王海龙 on 2021/4/5.
//测试虚函数 实现函数多态
// Java语言默认支持多态
// C++默认关闭多态，怎么开启多态？ 虚函数  在父类上给函数增加 virtual关键字

#include <iostream>

using namespace std;

// Android标准
class BaseActivity {
public:
    virtual void onStart() {
        cout << "BaseActivity onStart" << endl;
    }
};

class HomeActivity : public BaseActivity {
public:
    void onStart() { // 重写父类的函数
        cout << "HomeActivity onStart" << endl;
    }
};

class LoginActivity : public BaseActivity {
public:
    void onStart() { // 重写父类的函数
        cout << "LoginActivity onStart" << endl;
    }
};

// 在此函数 体系多态，例如：你传入HomeActivity，我就帮你运行HomeActivity
void startToActivity(BaseActivity *baseActivity) {
    baseActivity->onStart();
}

int main() {
    // TODO 第一版本
    HomeActivity *homeActivity = new HomeActivity();
    LoginActivity *loginActivity = new LoginActivity();

    startToActivity(homeActivity);
    startToActivity(loginActivity);

    if (homeActivity && loginActivity) delete homeActivity;
    delete loginActivity;

    cout << endl;

    // TODO 第二个版本
    BaseActivity *activity1 = new HomeActivity();
    BaseActivity *activity2 = new LoginActivity();
    startToActivity(activity1);
    startToActivity(activity2);

    if (homeActivity) {
        delete homeActivity;
    }
    if (loginActivity) {
        delete loginActivity;
    }

    // TODO 抛开 C++ 抛开Java 等等，请问什么是多态？ 父类的引用指向之子类对象，同一个方法有不同的实现，重写（动态多态）和   重载(静态多态)

    return 0;
}


