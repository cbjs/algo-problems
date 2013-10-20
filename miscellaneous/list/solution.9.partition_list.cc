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
    ListNode *partition(ListNode *head, int x) {
        ListNode *le_head = nullptr, *ge_head = nullptr, *le_tail = nullptr, *ge_tail = nullptr;
        ListNode *p = head;
        while (p) {
            if (p->val < x) {
                if (!le_head) {
                    le_head = p;
                    le_tail = p;
                } else {
                    le_tail->next = p;
                    le_tail = p;
                }
            } else {
                 if (!ge_head) {
                    ge_head = p;
                    ge_tail = p;
                } else {
                    ge_tail->next = p;
                    ge_tail = p;
                }
            }
            p = p->next;
        }
        if (ge_tail) ge_tail->next = nullptr;
        if (le_tail) le_tail->next = ge_head;
        if (!le_head) le_head = ge_head;
        return le_head;
    }
};
