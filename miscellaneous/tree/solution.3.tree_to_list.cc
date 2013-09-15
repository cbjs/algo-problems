#include <iostream>

using namespace std;

class Node {
  public:
        Node(int value = -1) : v(value), l(NULL), r(NULL) {}

  public:
        int v;
        Node* l;
        Node* r;
};

Node * tree_to_list(Node* root) {
    if (!root) return NULL;

    Node* left_head = tree_to_list(root->l);
    Node* right_head = tree_to_list(root->r);

    Node* tail = root;
    if (left_head) {
        tail->r = left_head;
        while(tail->r != NULL) tail = tail->r;
    }

    tail->r = right_head;

    return root;
}
