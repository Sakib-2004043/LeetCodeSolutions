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
public:
    int ans = 0;
    void dfs_sum(TreeNode* node, int sum) {
        sum = sum * 10 + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            ans += sum;
            sum = 0;
        }
        if (node->left != nullptr) {
            dfs_sum(node->left, sum);
        }
        if (node->right != nullptr) {
            dfs_sum(node->right, sum);
        }
    }
    int sumNumbers(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        dfs_sum(root, 0);
        return ans;
    }
};