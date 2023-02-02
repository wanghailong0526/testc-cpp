//
// Created by 王海龙 on 2023/1/14.
//
/**
 * 链表反转
 */
#include "link.h"

Node linkReverse(Node list) {
    Node curr = list;
    Node p = nullptr;
    Node next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = p;
        p = curr;
        curr = next;
    }
    return p;//反转后的头结点
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

    printf("反转前 ");
    printLink(head);
    printf("反转后 ");
    printLink(linkReverse(head));

    free(head);
    free(ele1);
    free(ele2);
    free(ele3);
    free(ele4);
}

