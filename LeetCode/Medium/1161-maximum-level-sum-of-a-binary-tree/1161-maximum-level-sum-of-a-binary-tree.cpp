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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 1, best = 1, maxSum = INT_MIN;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            int curSum = 0;
            while (sz--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                curSum += node->val;
            }
            if (curSum > maxSum) {
                best = level;
                maxSum = curSum;
            }
            level++;
        }
        return best;
    }
};