//
// Created by 王海龙 on 2022/9/17.
//
/**
 * pthread
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>//包含 sleep(秒) usleep(微秒)函数

void *myfun(void *);

int main(int argc, const char **argv) {
    printf("main thread \n");
    pthread_t tid;
    //创建 0_成功 非0_失败
    int i = pthread_create(&tid, NULL, myfun, 1);
    printf("pthread_create i=%d\n", i);
    //pthread_join避免主线程结束后，子线程也结束了，导致子线程无输出
    //方法1
//    sleep(1);//不加这行语句，主线程结束后，子线程也结束了，可能无法打印myfun方法执行结果
    //方法2
    void *retVal;
    pthread_join(tid, &retVal);//作用:主线程等待 tid 线程结束后，将返回值放到 retVal 中，主线程再退出
    printf("接收到子线程的返回值=%d\n", (int) retVal);
}

void *myfun(void *arg) {
    int *parg = (int *) arg;
    printf("thread, i=%d\n", parg);
    //下面方法用于线程结束时的返回值
    //方法1
//    pthread_exit(2);//退出线程，将返回值给pthread_join(tid,返回值)
    //方法2
    return 50;//退出码，返回值是我们自己定义的 用于pthread_jon(tid,返回值)

}

