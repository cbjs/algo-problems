#include <iostream>

/**
 * 思路: 两次遍历二叉树
 *  round 1: 后序遍历，统计以每个节点为根的子树中的节点数nodes和石头数stones
 *              若石头数大于节点数，将多出来的石头向上搬运至父节点
 *              stones = stones(left_child) + stones(right_child) + current_node_stone
 *              nodes = nodes(left_child) + nodes(right_child) + 1
 *
 *  round 2: 前序遍历，将根节点上多出来的石头分别搬运到左右子节点上
 */

using namespace std;

class Node {
  public:
        Node(int value = -1) : v(value), l(NULL), r(NULL) {}

  public:
        int v;
        Node* l;
        Node* r;
};

/**
 * Round One, 返回搬运次数
 *  如果当前节点上的石头数大于节点数，搬运至父节点
 *  修改当前节点上的v值表示当前子树上缺少的石头数, 用于下一阶段, 从上向下搬运
 */
int post_order(Node* root, Node* parent) {
    // 处理空指针
    if (!root) return 0;

    // 左子树, 返回搬运次数
    int l_num = post_order(root->l, root);
    // 右子树, 返回搬运次数
    int r_num = post_order(root->r, root);

    // 计算以当前节点为根的子树，缺少的石头
    int stones_short = 1 + root->l ? root->l->v : 0 + root->r ? root->r->v : 0;

    // 用当前节点上石头数减去“缺少的石头”计算“剩下的石头”
    int stones_left = root->v - stones_short;

    // "剩下的石头"小于等于0，更新root->v为当前子树的缺少的石头数
    if (stones_left <= 0) {
        root->v = -1 * stones_left;
        // 返回当前子树中搬运次数
        return l_num + r_num;
    }

    // "剩下的石头"大于0，更新root->v = 0表示缺少的石头数为0
    root->v = 0;
    // 向上搬运石头
    parent->v += stones_left;
    // 返回当前子树中搬运次数
    return l_num + r_num + stones_left;
}

/**
 * Round Two, 返回搬运次数
 *  从根节点向下搬运石头
 */
int pre_order(Node* root) {
    if (!root) return 0;

    int num_carries = root->l ? root->l->v : 0 + root->r ? root->r->v : 0;

    root->v = 1;

    return pre_order(root->l) + pre_order(root->r) + num_carries;
}

int carry_stones(Node* root) {
    int up_order_num_carries = post_order(root, NULL);
    int down_order_num_carries = pre_order(root);

    std::cout << "num of carries:"
              << up_order_num_carries + down_order_num_carries
              << std::endl;
}

int main(int argc, char *argv[])
{
    Node* tree_root = NULL;
    carry_stones(tree_root);
    return 0;
}
