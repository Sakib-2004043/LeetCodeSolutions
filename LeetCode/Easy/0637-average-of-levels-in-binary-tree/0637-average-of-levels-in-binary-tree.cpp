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
    vector<double> averageOfLevels(TreeNode* root) {
        int i, sz;
        vector<double> avgs;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            sz = q.size();
            double avg = 0;
            for (i = 0; i < sz; i++) {
                TreeNode* curNode = q.front();
                q.pop();
                if (curNode->left != nullptr)
                    q.push(curNode->left);
                if (curNode->right != nullptr)
                    q.push(curNode->right);
                avg += curNode->val;
            }
            avgs.push_back(avg / sz);
        }
        return avgs;
    }
};