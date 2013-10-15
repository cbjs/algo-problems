/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode* p = head;
        while (p) {
            RandomListNode* new_node = new RandomListNode(p->label);
            new_node->next = p->next;
            p->next = new_node;
            p = new_node->next;
        }

        p = head;
        while(p) {
            if (p->random) p->next->random = p->random->next;
            p = p->next->next;
        }

        RandomListNode* new_list = head->next, *tail = NULL;
        p = head;
        while (p) {
            if (!tail) tail = p->next;
            else {
                tail->next = p->next;
                tail = tail->next;
            }
            p->next = p->next->next;
            p = p->next;
        }
        return new_list;
    }
};
