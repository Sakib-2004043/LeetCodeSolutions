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
    TreeNode* builder(auto& inorder, auto& postorder, int& postIdx, int left,
                      int right) {
        if (left > right) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postIdx]);
        int idx = idxMap[postorder[postIdx]];
        postIdx--;
        root->right = builder(inorder, postorder, postIdx, idx + 1, right);
        root->left = builder(inorder, postorder, postIdx, left, idx - 1);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ni = inorder.size();
        for (int i = 0; i < ni; i++) {
            idxMap[inorder[i]] = i;
        }
        int postIdx = ni - 1;
        return builder(inorder, postorder, postIdx, 0, ni - 1);
    }
};