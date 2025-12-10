/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;
    void dfs_count(TreeNode* root){
        if(root == nullptr){
            return;
        }
        else{
            count++;
        }
        dfs_count(root->left);
        dfs_count(root->right);
    }
    int countNodes(TreeNode* root) {
        dfs_count(root);
        return count;
    }
};