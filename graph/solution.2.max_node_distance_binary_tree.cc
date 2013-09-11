#include <iostream>

using namespace std;

#define max(a, b) ((a) > (b) ? (a) : (b))

class Node {
 public:
   explicit Node(int value = -1) : v(value), l(NULL), r(NULL){}
   Node* l;
   Node* r;
   int v;
};

void max_distance(Node* root, int* length, int* height) {
  if (!root) {
    *length = *height = -1;
    return;
  }

  int left_length, left_height;
  max_distance(root->l, &left_length, &left_height);

  int right_length, right_height;
  max_distance(root->r, &right_length, &right_height);

  *height = max(left_height, right_height) + 1;
  *length = max(max(left_length, right_length), left_height + right_height + 2);
}

int main(int argc, const char *argv[])
{
  // build a binary tree
  //        1
  //       / \
  //      2   3
  //     / \
  //    4   5
  //         \
  //          6

  Node nodes[6];
  for (int i = 0; i < 6; i++) {
    nodes[i].v = i + 1;
  }

  nodes[0].l = &nodes[1];
  nodes[0].r = &nodes[2];
  nodes[1].l = &nodes[3];
  nodes[1].r = &nodes[4];
  nodes[4].r = &nodes[5];

  int max_nodes_length, tree_height;
  max_distance(&nodes[0], &max_nodes_length, &tree_height);
  std::cout << "max nodes distance: " << max_nodes_length;
  return 0;
}
