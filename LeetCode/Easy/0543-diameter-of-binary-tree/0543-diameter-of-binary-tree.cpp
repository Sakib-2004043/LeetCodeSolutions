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
    int dfs(TreeNode* node, int& ans) {
        if (node == NULL) {
            return 0;
        }
        int lSum = dfs(node->left, ans);
        int rSum = dfs(node->right, ans);
        ans = max(ans, rSum + lSum);
        return max(lSum, rSum) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};