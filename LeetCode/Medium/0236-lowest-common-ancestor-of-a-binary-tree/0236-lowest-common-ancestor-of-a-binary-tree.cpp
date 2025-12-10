/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>ancestor;
    unordered_map<TreeNode*,bool>ancestorP;
    void lca_dfs(TreeNode* root){
        if(root == nullptr){
            return;
        }
        if(root->left != nullptr){
            ancestor[root->left] = root;
        }
        if(root->right != nullptr){
            ancestor[root->right]=root;
        }
        lca_dfs(root->left);
        lca_dfs(root->right);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int i,n;
        if(root == nullptr){
            return NULL;
        }
        ancestor[root] = NULL;
        lca_dfs(root);

        while(p != nullptr){
            ancestorP[p] = true;
            p = ancestor[p];
        }
        while(q!=nullptr){
            if(ancestorP[q]){
                return q;
            }
            q = ancestor[q];
        }
        return root;

    }
};