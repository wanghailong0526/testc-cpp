//
// Created by 王海龙 on 2022/9/14.
//
/**
 * STL standard template library 标准模板库
 * 1.字符串
 * 2.容器 vector 动态数组
 */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

int main() {
    /**********string********/
    string str = "1234567";
    string s = "abc";
    string r = str + s;//拼接
    const char *cStr = r.c_str();//string 转 char *
    cout << r << endl;
    char &at = r.at(2);
    cout << at << endl;
    /**********string********/

    /**********vector********/
    vector<int> v;
    v.push_back(10);
    v.push_back(11);
    v.push_back(12);
    int size = v.size();
    int i = 0;
    int *p = &v[0];
    for (; i < size; ++i) {
        cout << *p << endl;
        p++;
    }
    /**********vector********/

}
