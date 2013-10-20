/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

void recoverTree_Morris_Traversal(TreeNode *root) {
    TreeNode *p = root, *pre = nullptr, *first = nullptr, *second = nullptr;
    while (p) {
        if (!p->left) {
            if (pre && pre->val > p->val) {
                if (!first) {
                    first = pre;
                    second = p;
                } else {
                    second = p;
                }
            }
            pre = p;
            p = p->right;
            continue;
        }

        TreeNode* rightmost = p->left;
        while (rightmost->right && rightmost->right != p) rightmost = rightmost->right;
        if (!rightmost->right) {
            rightmost->right = p;
            p = p->left;
        } else {
            rightmost->right = nullptr;
            if (pre && pre->val > p->val) {
                if (!first) {
                    first = pre;
                    second = p;
                } else {
                    second = p;
                }
            }
            pre = p;
            p = p->right;
        }
    }
    // swap first & second
    int tmp = first->val;
    first->val = second->val;
    second->val = tmp;
}

void recoverTree_Recursive(TreeNode *root) {
    TreeNode *first = nullptr, *second = nullptr;
    _recoverTree(root, nullptr, first, second);
    if (first && second) {
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
}

TreeNode* _recoverTree(TreeNode* root, TreeNode* pre, TreeNode*& first, TreeNode*& second) {
    if (!root) return pre;

    if (left_right_most) {
        if (left_right_most->val > root->val) {
            if (!first) {
                first = left_right_most;
                second = root;
            } else {
                second = root;
            }
        }
    }
    return _recoverTree(root->right, root, first, second);
}
