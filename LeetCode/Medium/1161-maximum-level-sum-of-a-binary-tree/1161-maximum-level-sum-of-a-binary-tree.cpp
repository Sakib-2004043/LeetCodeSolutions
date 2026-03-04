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
    unordered_map<int, int> sum;
    void dfs(TreeNode* node, int level) {
        if (!node) {
            return;
        }
        sum[level] += node->val;
        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }

public:
    int maxLevelSum(TreeNode* root) {
        dfs(root, 1);
        int mx = INT_MIN, ans = 1;
        for (auto [l, s] : sum) {
            if (mx <= s) {
                ans = (mx == s) ? min(ans, l) : l;
                mx = s;
            }
        }
        return ans;
    }
};