#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head) return nullptr;
        ListNode *pre = nullptr, *p = head;
        int i = 1;
        while (p && i++ < m) {
            pre = p;
            p = p->next;
        }

        ListNode *t = nullptr, *last = p;
        while (p && i++ <= n) {
            ListNode *q = p->next;
            p->next = t;
            t = p;
            p = q;
        }

        if (last != p) last->next = p;

        if (pre) pre->next = t;
        return head;
    }
};

int main(int argc, char *argv[])
{
    ListNode n1(3);
    Solution().reverseBetween(&n1, 1, 1);
    return 0;
}
