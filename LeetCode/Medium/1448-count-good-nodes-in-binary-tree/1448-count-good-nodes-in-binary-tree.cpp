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
    int dfs(TreeNode* node, int mx) {
        if (!node) {
            return 0;
        }
        int ans = node->val >= mx ? 1 : 0;
        ans += dfs(node->left, max(mx, node->val));
        ans += dfs(node->right, max(mx, node->val));
        return ans;
    }

public:
    int goodNodes(TreeNode* root) { return dfs(root, INT_MIN); }
};