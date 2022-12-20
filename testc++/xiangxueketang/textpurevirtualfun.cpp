//
// Created by 王海龙 on 2021/4/5.
//测试纯虚函数 ==Java抽象类
//如果子类没有重写纯虚函数，子类就是抽象类
//如果一个类既有普通函数也有纯虚函数这个类就是抽象类
//如果一个类只有纯虚函数，这个类就是全纯虚函数，== Java 接口
#include <iostream>

using namespace std;

class BaseActivity {
private:
    void setContentView() {
        cout << "设置了view" << endl;
    }

public:
    void onCreate() {//普通函数
        setContentView();
        getLayoutId();
        initView();
        initData();
        initListener();
    }

    //如果子类没有重写纯虚函数，子类就是抽象类
    virtual int getLayoutId() = 0;//纯虚函数
    virtual void initView() = 0;//纯虚函数
    virtual void initData() = 0;//纯虚函数
    virtual void initListener() = 0;//纯虚函数
};

class MainActivity : BaseActivity {
public:
    MainActivity() {
        getLayoutId();
        initView();
        initData();
        initListener();
    }

    int getLayoutId() {
        cout << "调用了 getLayoutId()" << endl;
        return 0;
    }

    void initView() {
        cout << "调用了 initView()" << endl;
    }

    void initData() {
        cout << "调用了 initData()" << endl;
    }

    void initListener() {
        cout << "调用了 initListener()" << endl;
    }
};

int main() {
    MainActivity mainActivity;
}
