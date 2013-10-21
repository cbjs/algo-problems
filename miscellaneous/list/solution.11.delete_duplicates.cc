#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *deleteDuplicates(ListNode *head) {
    if (!head) return nullptr;

    ListNode *p = head, *q = nullptr, *prev = nullptr;
    head = nullptr;
    while (p) {
        q = p->next;
        while (q && q->val == p->val) {
            ListNode *t = q->next;
            delete q;
            q = t;
        }
        if (q == p->next) {
            if (!prev) {
                head = p;
                prev = p;
            } else {
                prev->next = p;
                prev = p;
            }
        }
        p = q;
    }
    if (prev) prev->next = nullptr;
    return head;
}
