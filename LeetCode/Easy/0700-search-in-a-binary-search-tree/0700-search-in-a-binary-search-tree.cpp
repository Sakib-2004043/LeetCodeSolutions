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
    TreeNode* dfs(TreeNode* node, int val) {
        if (!node) {
            return nullptr;
        }
        if (node->val == val) {
            return node;
        }
        TreeNode* left = dfs(node->left, val);
        TreeNode* right = dfs(node->right, val);
        return left ? left : right;
    }

public:
    TreeNode* searchBST(TreeNode* root, int val) { return dfs(root, val); }
};