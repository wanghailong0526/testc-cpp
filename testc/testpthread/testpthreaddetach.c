//
// Created by 王海龙 on 2022/12/21.
//
/**
 * 线程分离状态
 * 两种方法设置
 * 1.pthread_attr_setdetachstate(&attr_odd, PTHREAD_CREATE_DETACHED)
 * 2.在线程方法里添加
 *  pthread_detach(pthread_self());
 *
 *  代码 .........
 *
 *  pthread_exit(NULL);
 *
 * 线程分离要点:
 * 1.当线程结束后自动释放占用的资源
 * 2.如果使用 pthread_join() 会阻塞主线程，主线程等待子线程执行结束后(子线程会释放资源)才会继续执行,线程分离后不会阻塞主线程执行
 * 3.线程分离后子线程要退出 pthread_exit(NULL)
 *
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define LOOP 30
int i = 0;

//打印奇数
void *printOddNumber(void *arg) {
//    pthread_detach(pthread_self());//此线程是分离状态，线程结束会自动释放自己占用的资源
    char *consumer = (char *) arg;
    while (i < LOOP) {
        //是奇数就打印
        if (i < LOOP && i & 1) {
            printf("%s:%d\n", consumer, i);
            fflush(NULL);
            sleep(1);
        }
        ++i;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_attr_t attr_odd;
    pthread_attr_init(&attr_odd);
    // PTHREAD_CREATE_JOINABLE 创建的线程与主线程不是分离的
    pthread_attr_setdetachstate(&attr_odd, PTHREAD_CREATE_DETACHED);//线程创建默认为非分离状态,这里设置为分离状态,不需要主线等待子线程执行结束，主线程才退出

    pthread_t tid_odd_number;
    pthread_create(&tid_odd_number, &attr_odd, printOddNumber, "printOddNumber");//打印奇数

//    pthread_join(tid_odd_number, NULL);//阻塞主线程
    printf("main方法执行结束！");
}

