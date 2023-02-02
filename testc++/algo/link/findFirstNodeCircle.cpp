//
// Created by 王海龙 on 2023/1/15.
//
/**
 * 检测入环的第一个结点
 */
#include "link.h"

Node findFirstNodeIntoCircle(Node list) {
    Node fast = list;
    Node slow = list;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {//证明有环
            slow = list;
            while (fast != slow) {//fast 与 slow 不相遇  相遇时slow就是入环的第一个结点
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return nullptr;
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
    ele4->next = head;

    Node temp = findFirstNodeIntoCircle(head);
    printf("入环结点的值 = %d\n", !temp ? -1 : temp->data);

    free(head);
    free(ele1);
    free(ele2);
    free(ele3);
    free(ele4);
}