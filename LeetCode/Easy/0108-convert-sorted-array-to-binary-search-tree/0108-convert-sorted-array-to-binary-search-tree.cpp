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
    TreeNode* divide_and_conqueror(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        TreeNode* newNode = new TreeNode(nums[mid]);
        newNode->left = divide_and_conqueror(nums, left, mid - 1);
        newNode->right = divide_and_conqueror(nums, mid + 1, right);
        return newNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return divide_and_conqueror(nums, 0, nums.size() - 1);
    }
};