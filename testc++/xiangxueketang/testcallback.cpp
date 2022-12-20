//
// Created by 王海龙 on 2021/4/5.
//测试函数回调
#include <iostream>

using namespace std;

class LoginBean {
public:
    string name;

    LoginBean(const string &name) : name(name) {}
};

//登录回调接口 全纯虚函数
class IResponse {
public:
    virtual void onSuccess(int code, string mes, LoginBean loginBean) = 0;

    virtual void onFail(int code, string msg) = 0;
};

class IResponseImpl : public IResponse {
public:
    void onSuccess(int code, string msg, LoginBean loginBean) {
        cout << "登录成功 " << "code:" << code << " msg:" << msg << " userName:" << loginBean.name << endl;
    }

    void onFail(int code, string msg) {
        cout << "登录失败" << "code:" << code << " msg:" << msg << endl;
    }
};

void login(string name, string pwd, IResponse &response) {
    if (name.empty() || pwd.empty()) {
        response.onFail(404, "账号或密码为空");
        return;
    }
    if ("whl" == name && "123" == pwd) {
        response.onSuccess(200, "登录成功", LoginBean("whl"));
    } else {
        response.onFail(404, "登录失败，账号或密码错误");
    }
}

int main() {
    IResponseImpl iResponseImpl;
    string name = "whl";
    string pwd = "123";
    login(name, pwd, iResponseImpl);

    name = "whl1";
    pwd = "1231";
    login(name, pwd, iResponseImpl);

    name = "";
    pwd = "";
    login(name, pwd, iResponseImpl);

    return 0;
}

