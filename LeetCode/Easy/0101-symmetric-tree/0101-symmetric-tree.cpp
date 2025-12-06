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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Case 1: both nodes are null → same
        if (!p && !q)
            return true;

        // Case 2: one null, one not → different
        if (!p || !q)
            return false;

        // Case 3: values don't match → different
        if (p->val != q->val)
            return false;

        // Case 4: recursively compare left and right
        return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left, root->right);
    }
};