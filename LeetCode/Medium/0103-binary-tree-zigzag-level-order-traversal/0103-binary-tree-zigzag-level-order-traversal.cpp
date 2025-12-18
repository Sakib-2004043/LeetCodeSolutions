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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        int i, sz;
        bool k = false;
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            sz = q.size();
            vector<int> level;
            for (i = 0; i < sz; i++) {
                if (q.front()->right != nullptr) {
                    q.push(q.front()->right);
                }
                if (q.front()->left != nullptr) {
                    q.push(q.front()->left);
                }
                level.push_back(q.front()->val);
                q.pop();
            }
            k = !k;
            if (k) {
                reverse(level.begin(), level.end());
            }
            ans.push_back(level);
        }
        return ans;
    }
};