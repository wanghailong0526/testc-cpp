//
// Created by 王海龙 on 2021/4/7.
//
#include <iostream>
#include <pthread.h>
#include <stdlib.h>

using namespace std;

#define NUM_IDS 5
struct thread_data {
    int threadId;
    char *msg;
};

void *sayHello(void *data) {
    struct thread_data *my_data;
    my_data = (struct thread_data *) data;
    cout << "ThreadId:" << my_data->threadId << endl;
    cout << "msg:" << my_data->msg << endl;
    pthread_exit(NULL);
}

int main() {
    pthread_t ids[NUM_IDS];
    struct thread_data td[NUM_IDS];
    int i;
    for (i = 0; i < NUM_IDS; i++) {
        td[i].threadId = i;
        td[i].msg = (char *) "this is message";
        int rec = pthread_create(&ids[i], NULL, sayHello, (void *) &td[i]);
        if (rec != 0) {
            cout << "Error create thread!" << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}


