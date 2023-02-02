//
// Created by 王海龙 on 2023/1/17.
//
/**
 * 两个有序链表合并
 */
#include "link.h"

Node mergeTwoOrderLink(Node l1, Node l2) {
    Node soldier = (Node) malloc(sizeof(node));
    Node p = soldier;
    while (l1 && l2) {
        if (l1->data < l2->data) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    if (l1) {
        p->next = l1;
    }
    if (l2) {
        p->next = l2;
    }
    return soldier->next;
}

int main() {
    Node l1 = (Node) malloc(sizeof(node));
    l1->data = 1;
    Node ele1 = (Node) malloc(sizeof(node));
    ele1->data = 3;
    Node ele2 = (Node) malloc(sizeof(node));
    ele2->data = 5;
    Node ele3 = (Node) malloc(sizeof(node));
    ele3->data = 7;
    Node ele4 = (Node) malloc(sizeof(node));
    ele4->data = 9;

    l1->next = ele1;
    ele1->next = ele2;
    ele2->next = ele3;
    ele3->next = ele4;
    ele4->next = nullptr;

    Node l2 = (Node) malloc(sizeof(node));
    l2->data = 2;
    Node ele5 = (Node) malloc(sizeof(node));
    ele5->data = 4;
    Node ele6 = (Node) malloc(sizeof(node));
    ele6->data = 6;
    Node ele7 = (Node) malloc(sizeof(node));
    ele7->data = 8;
    Node ele8 = (Node) malloc(sizeof(node));
    ele8->data = 10;
    Node ele9 = (Node) malloc(sizeof(node));
    ele9->data = 15;

    l2->next = ele5;
    ele5->next = ele6;
    ele6->next = ele7;
    ele7->next = ele8;
    ele8->next = ele9;
    ele9->next = nullptr;

    Node temp = mergeTwoOrderLink(l1, l2);
    printLink(temp);

    free(l1);
    free(ele1);
    free(ele2);
    free(ele3);
    free(ele4);

    free(l2);
    free(ele5);
    free(ele6);
    free(ele7);
    free(ele8);
}

