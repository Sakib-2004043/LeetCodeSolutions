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
private:
    TreeNode* findNode(TreeNode* node, auto& parents, int target) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->val == target) {
            return node;
        }
        TreeNode *leftNode = NULL, *rightNode = NULL;
        if (node->left != nullptr) {
            leftNode = findNode(node->left, parents, target);
            if (leftNode != nullptr) {
                parents[node->left->val] = node;
            }
        }
        if (node->right != nullptr) {
            rightNode = findNode(node->right, parents, target);
            if (rightNode != nullptr) {
                parents[node->right->val] = node;
            }
        }
        return leftNode != nullptr ? leftNode : rightNode;
    }
    void getAns(TreeNode* node, auto& parents, auto& ans, int k, int now) {
        if (node == nullptr) {
            return;
        }
        if (k == now) {
            ans.push_back(node->val);
            return;
        }
        if (node->left != nullptr && parents[node->left->val] != node) {
            getAns(node->left, parents, ans, k, now + 1);
        }
        if (node->right != nullptr && parents[node->right->val] != node) {
            getAns(node->right, parents, ans, k, now + 1);
        }
        if (parents.count(node->val) != 0) {
            getAns(parents[node->val], parents, ans, k, now + 1);
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, TreeNode*> parents;
        parents[root->val] = nullptr;
        TreeNode* targetNode = findNode(root, parents, target->val);
        cout << targetNode->val;
        vector<int> ans;
        getAns(target, parents, ans, k, 0);
        return ans;
    }
};
