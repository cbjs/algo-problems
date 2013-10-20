/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

void recoverTree_Morris_Traversal(TreeNode *root) {
    // p for iterating
    // pre for previous node
    // first & second for two swapped node
    TreeNode *p = root, *pre = nullptr, *first = nullptr, *second = nullptr;
    while (p) {
        if (!p->left) {
            // visit p while p->left is null
            if (pre && pre->val > p->val) {
                if (!first) {
                    first = pre;
                    second = p;
                } else {
                    second = p;
                }
            }
            // keep track of pre
            pre = p;
            p = p->right;
            continue;
        }

        // set right ptr of the rightmost node of left subtree to p
        TreeNode* rightmost = p->left;
        while (rightmost->right && rightmost->right != p) rightmost = rightmost->right;

        // it' s first time visiting p if rightmost->right is null
        if (!rightmost->right) {
            rightmost->right = p;
            p = p->left;
        } else {
            // second time
            // restore rightmost's right ptr and visit p
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

    TreeNode *left_right_most = _recoverTree(root->left, pre, first, second);

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
