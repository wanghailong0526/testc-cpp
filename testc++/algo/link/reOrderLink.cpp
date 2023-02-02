//
// Created by 王海龙 on 2023/1/18.
//
/**
 * 重排链表
 * 给定一个有序链表 重新排序为 L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * 输入：head = [1,2,3,4,5]
 * 输出：[1,5,2,4,3]
 * 思路 先排第1个，再排倒数第1个，接着排第2个，紧接着倒数第2个
 */

#include "link.h"

Node reOrderLink(Node list) {
    if (!list->next) return list;
    Node soldier = (Node) malloc(sizeof(node));
    Node temp = soldier;

    //找中间结点
    Node fast = list;
    Node slow = list;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    //后半部分链表反转,反转后头结点为p
    Node curr = slow->next;//中间结点的下一个结点
    slow->next = nullptr;//从中间断开
    Node p = nullptr;
    Node next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = p;
        p = curr;
        curr = next;
    }

    //合并
    while (list && p) {
        temp->next = list;
        list = list->next;
        temp = temp->next;
        temp->next = p;
        p = p->next;
        temp = temp->next;
    }
    temp->next = list;
    return soldier->next;
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
//    Node ele4 = (Node) malloc(sizeof(node));
//    ele4->data = 4;

    head->next = ele1;
    ele1->next = ele2;
    ele2->next = ele3;
    ele3->next = nullptr;
//    ele4->next = nullptr;

    printf("原链表 ");
    printLink(head);
    printf("重排后 ");
    printLink(reOrderLink(head));

    free(head);
    free(ele1);
    free(ele2);
    free(ele3);
//    free(ele4);
}

