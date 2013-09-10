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

Node* reverse()

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
    return 0;
}
