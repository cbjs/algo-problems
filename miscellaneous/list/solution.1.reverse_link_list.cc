#include <iostream>

using namespace std;

typedef struct _Node{
    _Node(int value = 0) : v(value), n(NULL) {}

    void print() {
        _Node* head = this;
        while(head) {
            std::cout << head->v << ",";
            head = head->n;
        }
        std::cout << std::endl;
    }
    int v;
    _Node* n;
} Node;

Node* reverse(Node* head) {
    if (!head) return NULL;

    Node* new_head = NULL;
    Node* old_head = head;

    while (old_head) {
        Node* tmp = old_head->n;
        old_head->n = new_head;
        new_head = old_head;
        old_head = tmp;
    }

    return new_head;
}

int main(int argc, char *argv[])
{
    Node nodes[10];
    for (int i = 0; i < sizeof(nodes) / sizeof(Node); i++) {
        nodes[i].v = i;
        if (i > 0) {
            nodes[i - 1].n = &(nodes[i]);
        }
    }
    nodes[0].print();

    Node* reversed = reverse(&(nodes[0]));
    reversed->print();

    return 0;
}
