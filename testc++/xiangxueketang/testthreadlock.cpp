//
// Created by 王海龙 on 2021/4/27.
// 测试互斥锁
#include <iostream>
#include <pthread.h>
#include <queue>//队列
#include <unistd.h>//sleep(秒);

using namespace std;

queue<int> queueData;//int 全局队列 存放数据

pthread_mutex_t mutex_lock;//定义互斥锁
//void *(*)(void * pdata)
void *task(void *p_data) {
    //加锁
    pthread_mutex_lock(&mutex_lock);
    int threadid = *static_cast<int *>(p_data);
    cout << "当前线程:" << threadid << endl;
    if (!queueData.empty()) {//队列不为空，取数据
        printf("%d线程获取数据:", queueData.front());//取数据
        queueData.pop();//取出数据后，让数据出栈(删除数据)
    } else {
        cout << "没有数据了！" << endl;
    }

    //释放锁
    pthread_mutex_unlock(&mutex_lock);


    return 0;
}

int main() {
    pthread_mutex_init(&mutex_lock, NULL);
    for (int i = 111110; i < 1200000; i++) {
        queueData.push(i);
    }
    //定义多个线程
    pthread_t pthreadIdArray[10];
    for (int i = 0; i < 10; i++) {
        pthread_create(&pthreadIdArray[i], NULL, task, &i);
        pthread_join(pthreadIdArray[i], NULL);
    }
    sleep(12);
    pthread_mutex_destroy(&mutex_lock);
    cout << "main函数即将弹栈..." << endl;

    return 0;
}








