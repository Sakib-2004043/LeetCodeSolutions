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
    unordered_map<int, int> idxMap;
    TreeNode* builder(auto& preorder, auto& inorder, int& preIdx, int left,
                      int right) {
        if (left > right) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preIdx]);
        int idx = idxMap[preorder[preIdx]];
        preIdx++;
        root->left = builder(preorder, inorder, preIdx, left, idx - 1);
        root->right = builder(preorder, inorder, preIdx, idx + 1, right);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ni = inorder.size();
        for (int i = 0; i < ni; i++) {
            idxMap[inorder[i]] = i;
        }
        int preIdx = 0;
        return builder(preorder, inorder, preIdx, 0, ni - 1);
    }
};