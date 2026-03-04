/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    vector<int> dfs(TreeNode* node, vector<int>& leaf) {
        if (!node->left && !node->right) {
            leaf.push_back(node->val);
        }
        if (node->left) {
            dfs(node->left, leaf);
        }
        if (node->right) {
            dfs(node->right, leaf);
        }
        return leaf;
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        return dfs(root1, leaf1) == dfs(root2, leaf2);
    }
};