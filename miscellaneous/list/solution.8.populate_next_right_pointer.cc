/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode* sibling_left = NULL;
        TreeLinkNode* sibling = root->next;
        while (sibling && !sibling_left) {
            if (sibling->left) sibling_left = sibling->left;
            else sibling_left = sibling->right;
            sibling = sibling->next;
        }

        if (root->right) {
            root->right->next = sibling_left;
        }

        if (root->left) {
            if (root->right) {
                root->left->next = root->right;
            } else {
                root->left->next = sibling_left;
            }
        }

        connect(root->right);
        connect(root->left);
    }
};
