//
//  deepcopy.resource
//  test
//
//  Created by 王海龙 on 2021/2/18.
//  类的深拷贝

#include <iostream>
#include <cstring>//strcpy() strlen()函数使用
#include <string>
using namespace std;

class Status{
public:
    int a;
    int b;
//private:
    char *str;
    string class_name;

    Status(int a,int b, char *str,string class_name);//构造函数
    ~Status();
    //拷贝构造函数,实现深拷贝，参数为Status的引用,若无此方法将报错，默认拷贝构造函数str为浅拷贝，这样就删除了两次
    //malloc: *** error for object 0x100466d80: pointer being freed was not allocated
    Status(Status &s);
    void print();
};

Status::Status(int a,int b, char *str,string class_name)
{
    this->a = a;
    this->b = b;
    this->class_name = class_name;
    this->str = new char[strlen(str)+1];
    strcpy(this->str, str);
    cout <<class_name << " invoke init" << endl;
}

Status::~Status()
{
    cout << class_name <<" invoke delete" << endl;
    delete [] str;
}

Status::Status(Status &s)
{
    this->a = s.a;
    this->b = s.b;
    this->class_name = s.class_name;
    this->str = new char[strlen(s.str)+1];
    strcpy(this->str, s.str);
}

void Status::print()
{
    cout << a << "/" << b << "/" << str << endl;
}

int main(int argc ,const char * argv[])
{
    char *p = "akdfalksdjfa;kdjfa;kdsf";

    Status st(1,2,p,"st");
    st.print();
    st.str[0]='c';
    st.print();

    Status ss(st);
    ss.print();

    Status hh(3,4,"abc","hh");

    return 0;
}
