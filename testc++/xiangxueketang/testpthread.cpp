//
// Created by 王海龙 on 2021/4/7.
//
#include <iostream>
#include <pthread.h>

using namespace std;
//#define NUM_THREADS 5
const int NUM_THREADS = 5;

void *sayHello(void *args) {
    cout << "执行了" << endl;
    return 0;
}

int main() {
    pthread_t tids[NUM_THREADS];
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        int ret = pthread_create(&tids[i], NULL, sayHello, NULL);
        if (ret != 0) {
            cout << "pthread create error" << endl;
        }
    }
    pthread_exit(NULL);

    return 0;
}
