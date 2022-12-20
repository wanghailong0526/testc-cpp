//
// Created by 王海龙 on 2022/11/26.
//
/**
 * using 指定别名
 * c 使用 typedef 指定别名
 */
#include <queue>
#include <iostream>

using FP = void (*)(const std::string &);//定义函数指针
typedef void (*PF)(const std::string &);

template<typename T>
class SafeQueue {
private:
    using queue_type = std::queue<T>;//定义别名 queue<T>的别名为queue_type
    queue_type data_queue;


public:
    SafeQueue() {}


    static void printMsg(const std::string &str) {
        std::cout << "str is " << str << std::endl;
    }

//    FP func=printMsg;
};

int main() {
    SafeQueue<std::string> data_queue;
    FP fp = data_queue.printMsg;
    fp("kwg kwg kwg ");


}