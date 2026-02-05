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
    int ans = -1e4;
    int dfs_sum(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int ls = dfs_sum(node->left);
        int rs = dfs_sum(node->right);
        int vl = node->val;
        ans = max({ans, ls + rs + vl, ls + vl, rs + vl, vl});
        return max({ls + vl, rs + vl, vl});
    }

public:
    int maxPathSum(TreeNode* root) {
        int val = dfs_sum(root);
        return ans;
    }
};