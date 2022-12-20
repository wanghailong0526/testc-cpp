//
// Created by 王海龙 on 2022/11/27.
//
/**
 * 模板别名
 * using 能做到，typedef做不到
 */
#include <vector>
/**
 * 模板别名
 */
// template<typename S>
//typedef std::vector<S,std::allocator<S>> ss;//报错 A typedef cannot be a template
template<typename T>
using Vec = std::vector<T, std::allocator<T>>;

int main() {
    //使用
    Vec<std::string> vec;
}
