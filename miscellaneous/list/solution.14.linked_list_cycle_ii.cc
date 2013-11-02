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
    ListNode *detectCycle(ListNode *head) {
       ListNode *slow_ptr = head, *fast_ptr = head;
       while (fast_ptr && fast_ptr->next) {
           slow_ptr = slow_ptr->next;
           fast_ptr = fast_ptr->next->next;

           if (slow_ptr && slow_ptr == fast_ptr) break;
       }

       if (!fast_ptr || !fast_ptr->next) return nullptr;

       slow_ptr = head;
       while (slow_ptr != fast_ptr) {
           slow_ptr = slow_ptr->next;
           fast_ptr = fast_ptr->next;
       }

       return slow_ptr;
    }
};
