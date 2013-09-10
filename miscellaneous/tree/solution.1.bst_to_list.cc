#include <iostream>

using namespace std;

class Node {
  public:
        Node(int value = 0) : v(value), l(NULL), r(NULL) {}

  public:
        int v;
        Node* l;
        Node* r;
};

Node* bst_to_list(Node* root) {
    if (!root) return NULL;

    Node* left_head = bst_to_list(root->l);
    Node* right_head = bst_to_list(root->r);

    root->r = right_head;
    if (!left_head) return root;

    Node* left_tail = left_head;
    while (left_tail->r) left_tail = left_tail->r;
    left_tail->r = root;

    return left_head;
}

void print(Node* head) {
    while(head) {
        std::cout << head->v << ",";
        head = head->r;
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    // 构造一棵BST
    Node n10(10);
    Node n6(6);
    Node n14(14);
    Node n4(4);
    Node n8(8);
    Node n12(12);
    Node n16(16);

    n10.l = &n6;
    n10.r = &n14;
    n6.l = &n4;
    n6.r = &n8;
    n14.l = &n12;
    n14.r = &n16;

    Node* list_head = bst_to_list(&n10);
    print(list_head);
    return 0;
}
