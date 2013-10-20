/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root) return;

        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if (left) {
            root->right = left;
            root->left = NULL;

            TreeNode* rightmost = left;
            while (rightmost->right) rightmost = rightmost->right;
            rightmost->right = right;
        }

        flatten(root->right);
    }
};
