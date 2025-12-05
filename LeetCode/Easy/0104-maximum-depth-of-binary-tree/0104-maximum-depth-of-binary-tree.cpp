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
    map<TreeNode*, bool> visited;
    int max_Depth = 0;

    void dfs(TreeNode* root, int depth) {
        visited[root] = true;
        max_Depth = max(max_Depth, depth);

        if (root->left != nullptr) {
            dfs(root->left, depth + 1);
        }
        if (root->right != nullptr) {
            dfs(root->right, depth + 1);
        }
    }
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        dfs(root, 1);
        return max_Depth;
    }
};