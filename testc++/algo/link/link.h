//
// Created by 王海龙 on 2023/1/14.
//

#ifndef TESTC_CPP_LINK_H
#define TESTC_CPP_LINK_H

#include <cstdio>
#include <cstdlib>// malloc 函数

typedef struct _Node *Node;
typedef struct _Node {
    int data;
    Node next;
} node;//此时 node 为 struct 类型

void printLink(Node list) {
    Node head = list;
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


#endif //TESTC_CPP_LINK_H
