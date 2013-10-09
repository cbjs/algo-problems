#include <iostream>

using namespace std;

typedef struct _Node{
    _Node(int v = 0) : value(v), next(NULL) {}

    void print() {
        _Node* head = this;
        while(head) {
            std::cout << head->value << "->";
            head = head->next;
        }
        std::cout << std::endl;
    }
    int value;
    _Node* next;
} Node;

// insert one by one then exchange nodes of remainder list pairwisely
//  1->2
//  1->3->2 insert "3", exchange 2-> pairwisely
//  1->4->2->3 insert "4", exchange 3->2 pairwisely
//  1->5->2->4->3 insert "5", exchange 4->2->3 pairwisely
void poly_solution(Node* head) {
    if (!head) return;
    Node* n = head->next;
    head->next = NULL;

    while(n) {
        Node* h = head->next;
        head->next = n;
        n = n->next;

        Node* t = head->next;
        t->next = h;

        // pairwise exchange
        while(h) {
            if(!h->next) break;

            t->next = h->next;
            h->next = h->next->next;
            t->next->next = h;

            t = h;
            h = h->next;
        }
    }
}

void linear_solution(Node* head) {
    if (!head || !head->next) return;
    // find mid node
    Node* slow_ptr = head;
    Node* fast_ptr = head;
    while(fast_ptr && fast_ptr->next) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    if (fast_ptr) slow_ptr = slow_ptr->next;

    // reverse list starting from mid
    Node* reversed_list = NULL;
    while(slow_ptr) {
        Node* tmp = slow_ptr->next;
        slow_ptr->next = reversed_list;
        reversed_list = slow_ptr;
        slow_ptr = tmp;
    }

    // interleave two halves
    Node* tail = head;
    while(reversed_list) {
        Node* tmp = tail->next;
        tail->next = reversed_list;
        reversed_list = reversed_list->next;
        tail->next->next = tmp;
        tail = tmp;
    }
    tail->next = NULL;
}

int main(int argc, char *argv[])
{
    Node nodes[3];
    for (int i = 0; i < sizeof(nodes) / sizeof(Node); i++) {
        nodes[i].value = i;
        if (i > 0) {
            nodes[i - 1].next = &(nodes[i]);
        }
    }
    nodes[0].print();

    linear_solution(&(nodes[0]));
    nodes[0].print();

    return 0;
}
