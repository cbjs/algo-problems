#include <iostream>

using namespace std;

class Node {
  public:
        Node(char value = '\0') : v(value), l(NULL), r(NULL) {}

  public:
        char v;
        Node* l;
        Node* r;
};

Node* rebuild_binary_tree(char* pre_order, char* in_order, int len) {
    if (len <=0) return NULL;

    Node* root = new Node(*pre_order);

    char* root_in_order = in_order;
    while(*root_in_order != *pre_order) ++root_in_order;

    int len_left = root_in_order - in_order;
    Node* left_root = rebuild_binary_tree(pre_order + 1, in_order, len_left);

    int len_right = len - len_left - 1;
    Node* right_root = rebuild_binary_tree(pre_order + len_left + 1, root_in_order + 1, len_right);

    root->l = left_root;
    root->r = right_root;
    return root;
}

void pre_order_traverse(Node* root) {
    if (!root) return;
    std::cout << root->v << ",";

    pre_order_traverse(root->l);
    pre_order_traverse(root->r);
}

void in_order_traverse(Node* root) {
    if (!root) return;

    in_order_traverse(root->l);
    std::cout << root->v << ",";
    in_order_traverse(root->r);
}

void post_order_traverse(Node* root) {
    if (!root) return;

    post_order_traverse(root->l);
    post_order_traverse(root->r);
    std::cout << root->v << ",";
}

int main(int argc, char *argv[])
{
    char pre_order[] = "abdefc";
    char in_order[] = "dbefac";

    Node* root = rebuild_binary_tree(pre_order, in_order, 6);
    std::cout << "pre_order:";
    pre_order_traverse(root);
    std::cout << std::endl;

    std::cout << "in_order:";
    in_order_traverse(root);
    std::cout << std::endl;
    return 0;
}
