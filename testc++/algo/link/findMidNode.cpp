//
// Created by 王海龙 on 2023/1/15.
//
/**
 * 链表查找中间结点
 */

#include "link.h"

Node findMidNode(Node list) {
    Node fast = list;
    Node slow = list;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main() {
    Node head = (Node) malloc(sizeof(node));
    head->data = 0;
    Node ele1 = (Node) malloc(sizeof(node));
    ele1->data = 1;
    Node ele2 = (Node) malloc(sizeof(node));
    ele2->data = 2;
    Node ele3 = (Node) malloc(sizeof(node));
    ele3->data = 3;
    Node ele4 = (Node) malloc(sizeof(node));
    ele4->data = 4;

    head->next = ele1;
    ele1->next = ele2;
    ele2->next = ele3;
    ele3->next = ele4;
    ele4->next = nullptr;

    printLink(head);
    Node temp = findMidNode(head);
    printf("中间结点的值 = %d\n", temp->data);

    free(head);
    free(ele1);
    free(ele2);
    free(ele3);
    free(ele4);
}