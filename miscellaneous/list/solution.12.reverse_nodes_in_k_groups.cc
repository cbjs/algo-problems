/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1) return head;

        ListNode *prev = nullptr, *p = head, *new_head = nullptr;

        while (p) {
            // find next
            int i = k;
            ListNode *next = p->next;
            while (--i > 0 && next) next = next->next;

            // less than k
            if (i > 0) break;

            // start reversing
            ListNode *tail = next, *t = nullptr, *new_prev = p;
            while (p != next) {
                t = p->next;
                p->next = tail;
                tail = p;
                p = t;
            }

            // link with previous group
            if (prev) {
                prev->next = tail;
            } else {
                new_head = tail;
            }

            prev = new_prev;
        }

        if (new_head) return new_head;

        return head;
    }
};
