class Solution {
public:
    stack<TreeNode*> st;

    void flat_dfs(TreeNode* root) {
        while (root != nullptr) {
            // push right child first
            if (root->right != nullptr) {
                st.push(root->right);
            }

            TreeNode* nextLeft = root->left; // save left before changing

            if (nextLeft != nullptr) {
                root->right = nextLeft;
            } else if (!st.empty()) {
                root->right = st.top();
                st.pop(); // pop after using
            }

            root->left = nullptr; // clear left pointer
            root = root->right;   // move along the right chain
        }
    }

    void flatten(TreeNode* root) {
        if (!root) return;

        st = stack<TreeNode*>();
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            flat_dfs(node);
        }
    }
};
