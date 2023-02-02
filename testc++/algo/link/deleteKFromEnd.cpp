//
// Created by 王海龙 on 2023/1/16.
//
/**
 * 删除倒数第K个结点
 * 返回删除的结点
 */
#include "link.h"

/**
 * 一级指针的引用代替二级指针在方法内部修改形参的值
 * @param list
 * @param k
 * @return delete node
 */
Node deleteKFromEnd(Node &list, int k) {
    Node fast = list;
    int i = 1;
    while (fast && i < k) {
        fast = fast->next;
        ++i;
    }
    if (!fast) return nullptr;//如果超过了链表长度

    Node slow = list;
    Node pre = nullptr;
    while (fast->next) {
        fast = fast->next;
        pre = slow;
        slow = slow->next;
    }
    //pre == null 删除的是第一个结点;否则删除的是其它结点
    !pre ? list = list->next : pre->next = pre->next->next;
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

    int k = 4;
    printLink(head);
    Node deleteNode = deleteKFromEnd(head, k);
    printf("倒数第 %d 个结点的值 = %d\n", k, !deleteNode ? -1 : deleteNode->data);
    printLink(head);

    free(head);
    free(ele1);
    free(ele2);
    free(ele3);
    free(ele4);
}
