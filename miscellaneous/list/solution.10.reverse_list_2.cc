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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
       if (m >= n) return head;

       ListNode *prev = nullptr, *p = head, *new_head = nullptr, *new_tail = nullptr;
       // find start node, keep track of previous node
       int i = 1;
       while (p && i < m) {
           prev = p;
           p = p->next;
           i++;
       }

       // start reversing, keep track of new tail and head of the reversed list
       new_tail = p;
       while (p && i <= n) {
           ListNode *q = p->next;
           p->next = new_head;
           new_head = p;
           p = q;
           i++;
       }

       // concate three parts
       new_tail->next = p;
       if (prev) {
           prev->next = new_head;
           return head;
       } else {
           return new_head;
       }
    }
};
