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
    int target = 0;
    bool dfs_sum(TreeNode* node, int sum) {
        if (node == nullptr)
            return false; // optional safety check
        sum += node->val;
        if (node->left == nullptr && node->right == nullptr) { // leaf node
            return sum == target;
        }
        // check left and right subtrees
        return dfs_sum(node->left, sum) || dfs_sum(node->right, sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        int sum = 0;
        target = targetSum;
        bool hasPath = dfs_sum(root, sum);
        return hasPath;
    }
};