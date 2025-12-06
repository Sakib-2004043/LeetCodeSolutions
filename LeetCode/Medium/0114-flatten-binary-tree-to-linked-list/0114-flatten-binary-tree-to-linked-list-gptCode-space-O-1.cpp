class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left != nullptr) {
                // Find the rightmost node of left subtree
                TreeNode* pred = curr->left;
                while (pred->right != nullptr) {
                    pred = pred->right;
                }

                // Rewire
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }

            curr = curr->right;  // move to next node
        }
    }
};
