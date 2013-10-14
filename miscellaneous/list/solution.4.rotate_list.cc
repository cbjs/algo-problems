#include <iostream>

// 右旋改左旋
ListNode *rotateRight(ListNode *head, int k) {
    if (!head || !head->next) return head;
    int len = 1;
    ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        ++len;
    }

    int left_rotate = (len - k % len) % len;
    while (left_rotate-- > 0) {
        tail->next = head;
        head = head->next;
        tail->next->next = NULL;
        tail = tail->next;
    }

    return head;
}
