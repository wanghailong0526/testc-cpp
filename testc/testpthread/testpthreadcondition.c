//
// Created by 王海龙 on 2022/9/17.
//
/**
 * 条件互斥锁
 * 打印偶数和奇数
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define LOOP 30
int i = 0;
pthread_mutex_t mutex;
pthread_cond_t cond;//条件变量

//打印偶数
void *printEvenNumber(void *arg) {
    char *printEvenNumber = (char *) arg;
    while (i < LOOP) {
        pthread_mutex_lock(&mutex);
        while (i & 1) {//奇数就等待
            //先解除之前的pthread_mutex_lock锁定的mtx
            //然后阻塞在等待队列里休眠,
            //直到再次被唤醒(大多数情况下是等待的条件成立而被唤醒或被惊群效应唤醒,唤醒后,该进程会先锁定pthread_mutex_lock(&mtx) )
            //再读取资源
            pthread_cond_wait(&cond, &mutex);//线程阻塞在这儿,不能继续运行了,下次从这里恢复继续执行
        }
        if (i < LOOP) {
            printf("%s: %d\n", printEvenNumber, i);
            fflush(NULL);//刷新缓冲区，显示打印结果
            usleep(1000*300);//微秒
        }
        ++i;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

//打印奇数
void *printOddNumber(void *arg) {
    char *printOddNumber = (char *) arg;
    while (i < LOOP) {
        pthread_mutex_lock(&mutex);
        while (!(i & 1)) {//偶数就等待
            pthread_cond_wait(&cond, &mutex);
        }
        //是奇数就打印
        if (i < LOOP) {
            printf("%s: %d\n", printOddNumber, i);
            fflush(NULL);
            usleep(1000*300);
        }
        ++i;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}


int main(int argc, const char **argv) {
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_t tid_odd_number, tid_even_number;
    pthread_create(&tid_odd_number, NULL, printOddNumber, "printOddNumber");//打印奇数
    pthread_create(&tid_even_number, NULL, printEvenNumber, "printEvenNumber");//打印偶数

    pthread_join(tid_odd_number, NULL);//第二个值是出参，接收 printOddNumber 函数的返回值
    pthread_join(tid_even_number, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}


