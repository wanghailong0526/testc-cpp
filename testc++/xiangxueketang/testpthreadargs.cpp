//
// Created by 王海龙 on 2021/4/7.
//
#include <iostream>
#include <pthread.h>

using namespace std;
#define NUM_TIDS 5

void *sayHello(void *pid) {
    int tid = *(static_cast<int *> (pid));
    cout << "线程ID:" << tid << endl;
    pthread_exit(NULL);
}

int main() {
    pthread_t ids[NUM_TIDS];
    int index[NUM_TIDS];
    int i;
    for (i = 0; i < NUM_TIDS; i++) {
        cout << "main创建线程" << i << endl;
        index[i] = i;//保存i的值
        //最后一个参数是指针函数的参数
        int ret = pthread_create(&ids[i], NULL, sayHello, static_cast<void *>(&(index[i])));
        if (ret != 0) {
            cout << "创建线程失败 code:" << ret << endl;
            exit(-1);
        }
    }

    pthread_exit(NULL);

    return 0;


}
