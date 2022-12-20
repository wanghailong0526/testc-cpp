//
// Created by 王海龙 on 2022/9/7.
//
class Student {
    //友元类 可以访问Student的所有成员和方法
    friend class Teacher;

private:
    char *name;
    int age;
public:
    char *getName() const {
        return name;
    }

    void setName(char *name) {
        Student::name = name;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Student::age = age;
    }
};

