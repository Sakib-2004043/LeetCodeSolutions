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
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int ans;
        vector<int> values;
        stack<TreeNode*> stc;
        stc.push(root);
        while (!stc.empty()) {
            TreeNode* curNode = stc.top();
            stc.pop();
            values.push_back(curNode->val);
            if (curNode->right != nullptr) {
                stc.push(curNode->right);
            }
            if (curNode->left != nullptr) {
                stc.push(curNode->left);
            }
        }
        sort(values.begin(), values.end());
        ans = INT_MAX;
        for (int i = 1; i < values.size(); i++) {
            ans = min(ans, values[i] - values[i - 1]);
        }
        return ans;
    }
};