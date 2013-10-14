#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumNumbers(TreeNode *root) {
    if (!root) return 0;
    // 叶结点，计算完成返回
    if (!root->left && !root->right) return root->val;

    int result = 0;
    if (root->left) root->left->val = root->val * 10 + root->left->val;
    if (root->right) root->right->val = root->val * 10 + root->right->val;

    // 非叶子结点汇总
    return sumNumbers(root->left) + sumNumbers(root->right);
}
