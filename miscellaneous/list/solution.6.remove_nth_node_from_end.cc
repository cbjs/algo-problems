struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 两个指针, q先向前走n步，再一起走，最后删除p指向的一下结点
// 注意边界条件, 当n为结点数, 要删除的是头结点的情况
ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode* p = head, *q = head;
    while (n-- > 0) q = q->next;
    if (!q) return p->next;
    while (q->next) {
        p = p->next;
        q = q->next;
    }
    p->next = p->next->next;
    return head;
}
