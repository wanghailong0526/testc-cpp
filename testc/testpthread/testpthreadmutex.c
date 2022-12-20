//
// Created by 王海龙 on 2022/9/17.
//
/**
 * 线程互斥
 * 1.声明 pthread_mutex_t mutex;
 * 2.初始化 mutex pthread_mutex_init(&mutex,NULL);
 * 3.加锁 pthread_mutex_lock(&mutex);
 * 4.解锁 pthread_mutex_unloc(&mutex);
 * 5.释放 pthread_mutex_destroy(&mutex);
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int i = 0;
pthread_mutex_t mutex;

void *func(void *arg) {
    //加锁
    pthread_mutex_lock(&mutex);
    char *parg = (char *) arg;
    for (; i < 5; ++i) {
        printf("%s:i=%d\n", parg, i);
        usleep(500);//线程睡眠
    }
    i = 0;
    //解锁
    pthread_mutex_unlock(&mutex);
    return 0;
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, func, "tid1");
    pthread_create(&tid2, NULL, func, "tid2");
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_mutex_destroy(&mutex);
}

