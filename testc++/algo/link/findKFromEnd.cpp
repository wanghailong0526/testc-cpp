//
// Created by 王海龙 on 2023/1/16.
//
/**
 * 查找倒数第K个结点
 * 快指针先走k步
 * 快慢指针再一起走
 * 当快指针走到最后一个结点时，慢指针指向的就是倒数第k个结点
 */

#include "link.h"

Node findKFromEnd(Node list, int k) {
    Node fast = list;
    int i = 1;
    while (fast && i < k) {
        fast = fast->next;
        ++i;
    }
    if (!fast) return nullptr;//如果超过了链表长度

    Node slow = list;
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main() {
    Node head = (Node) malloc(sizeof( node));
    head->data = 0;
    Node ele1 = (Node) malloc(sizeof( node));
    ele1->data = 1;
    Node ele2 = (Node) malloc(sizeof( node));
    ele2->data = 2;
    Node ele3 = (Node) malloc(sizeof( node));
    ele3->data = 3;
    Node ele4 = (Node) malloc(sizeof( node));
    ele4->data = 4;

    head->next = ele1;
    ele1->next = ele2;
    ele2->next = ele3;
    ele3->next = ele4;
    ele4->next = nullptr;

    int k = 5;

    Node temp = findKFromEnd(head, k);
    printf("倒数第 %d 个结点的值 = %d\n", k, !temp ? -1 : temp->data);

    free(head);
    free(ele1);
    free(ele2);
    free(ele3);
    free(ele4);
}

