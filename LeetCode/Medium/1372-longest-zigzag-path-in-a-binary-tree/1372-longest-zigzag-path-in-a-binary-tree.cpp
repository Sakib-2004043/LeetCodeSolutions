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
    int ans = 0;
    void zSumDFS(TreeNode* node, int zSum, int dir) {
        if (node == nullptr) {
            return;
        }
        ans = max(ans, zSum);
        zSumDFS(node->left, dir != -1 ? zSum + 1 : 1, -1);
        zSumDFS(node->right, dir != 1 ? zSum + 1 : 1, 1);
    }

public:
    int longestZigZag(TreeNode* root) {
        zSumDFS(root, 0, 0);
        return ans;
    }
};