class Solution {
public:
    bool dfs(TreeNode* node, long mn, long mx) {
        if (!node)
            return true;

        // node value must be strictly between mn and mx
        if (!(mn < node->val && node->val < mx))
            return false;

        return dfs(node->left, mn, node->val) &&
               dfs(node->right, node->val, mx);
    }

    bool isValidBST(TreeNode* root) { return dfs(root, LONG_MIN, LONG_MAX); }
};
