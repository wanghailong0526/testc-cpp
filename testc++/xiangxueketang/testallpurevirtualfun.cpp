//
// Created by 王海龙 on 2021/4/5.
//测试全纯虚函数
// 虚函数  纯虚函数 全纯虚函数（C++没有接口） 等价于  6.全纯虚函数（Java版接口）。

#include <iostream>

using namespace std;

class Student {
    int _id;
    string name;
    int age;
};

// 此类所有的函数 ，都是纯虚函数，就相当于 Java的接口了
class ISudent_DB {
    virtual void insertStudent(Student student) = 0;

    virtual void deleteStudent(int _id) = 0;

    virtual void updateStudent(int _id, Student student) = 0;

    virtual Student queryByStudent(Student student) = 0;
};

// Java的实现类
class Student_DBImpl1 : public ISudent_DB {
public:
    void insertStudent(Student student) {
        // 插入操作，省略代码...
    }

    void deleteStudent(int _id) {
        // 删除操作，省略代码...
    }

    void updateStudent(int _id, Student student) {
        // 更新操作，省略代码...
    }

    Student queryByStudent(Student student) {
        // 查询操作，省略代码...
        return student;
    }
};

// Java的实现类
class Student_DBImpl2 : public ISudent_DB {
public:
    void insertStudent(Student student) {
        // 插入操作，省略代码...
    }

    void deleteStudent(int _id) {
        // 删除操作，省略代码...
    }

    void updateStudent(int _id, Student student) {
        // 更新操作，省略代码...
    }

    Student queryByStudent(Student student) {
        // 查询操作，省略代码...
        return student;
    }
};

// Java的实现类
class Student_DBImpl3 : public ISudent_DB {
public:
    void insertStudent(Student student) {
        // 插入操作，省略代码...
    }

    void deleteStudent(int _id) {
        // 删除操作，省略代码...
    }

    void updateStudent(int _id, Student student) {
        // 更新操作，省略代码...
    }

    Student queryByStudent(Student student) {
        // 查询操作，省略代码...
        return student;
    }
};

class Iinterface {
public:
    virtual void initView() = 0;

    virtual void initData() = 0;

    virtual void initListener() = 0;
};

class H : Iinterface {
public:
    H() {
        initView();
        initData();
        initListener();
    }

    void initView() {
        cout << "调用了" << endl;
    }

    void initData() {
        cout << "调用了" << endl;
    }

    void initListener() {
        cout << "调用了" << endl;
    }
};

int main() {
    Student_DBImpl1 studentDbImpl1;
    Student_DBImpl2 studentDbImpl2;
    Student_DBImpl3 studentDbImpl3;

    cout << "student Success" << endl;

    H h;

    return 0;
}




