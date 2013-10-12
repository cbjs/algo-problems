/**
 * Definition for binary tree
 * struct TreeNode {
 *  int val;
 *  TreeNode *left;
 *  TreeNode *right;
 *  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/
class Solution {
    public:
    vector<TreeNode *> generateTrees(int n) {
    // Note: The Solution object is instantiated only once and is reused
    // by each test case.
        vector<TreeNode *> result;
        generateTrees(1, n, &result);
        return result;
    }

    void generateTrees(int s, int e, vector<TreeNode *>* result) {
        result->clear();
        if (s > e) {
            result->push_back(NULL);
            return;
        }

        vector<TreeNode *> left_child_tree;
        vector<TreeNode *> right_child_tree;
        for (int i = s; i <= e; ++i) {
            generateTrees(s, i - 1, &left_child_tree);
            generateTrees(i + 1, e, &right_child_tree);
            for (int j = 0; j < left_child_tree.size(); ++j) {
                for (int k = 0; k < right_child_tree.size(); ++k) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left_child_tree[j];
                    root->right = right_child_tree[k];
                    result->push_back(root);
                }
            }
        }
    }
};
