#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    void print () {
        ListNode* p = this;
        while (p) {
            cout << p->val;
            p = p->next;
        }
    }
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode* head = NULL;
    ListNode* pre = NULL;
    int carry = 0;
    while (l1 || l2) {
        ListNode* cur = new ListNode(carry);
        carry = 0;

        cout << "aa" <<carry << endl;

        if (l1) { cur->val += l1->val; l1 = l1->next; }
        if (l2) { cur->val += l2->val; l2 = l2->next; }
        if (cur->val >= 10) {
            cur->val -= 10;
            carry = 1;
        }

        if (!head) {
            head = cur;
            pre = cur;
        } else {
            pre->next = cur;
            pre = cur;
        }
    }

    if (carry && pre) {
        pre->next = new ListNode(1);
    }

    return head;
}

int main(int argc, char *argv[])
{
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(0);
    l1->print();
    l2->print();
    addTwoNumbers(l1, l2);
    return 0;
}
