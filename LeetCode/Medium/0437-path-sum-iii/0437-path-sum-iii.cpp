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
    void sumDFS(TreeNode* node, int target, vector<long long> sums) {
        if (node == nullptr) {
            return;
        }
        for (int i = 0; i < sums.size(); i++) {
            sums[i] += node->val;
            ans += (sums[i] == target) ? 1 : 0;
        }
        ans += (node->val == target) ? 1 : 0;
        sums.push_back(node->val);
        sumDFS(node->left, target, sums);
        sumDFS(node->right, target, sums);
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<long long> sums;
        sumDFS(root, targetSum, sums);
        return ans;
    }
};