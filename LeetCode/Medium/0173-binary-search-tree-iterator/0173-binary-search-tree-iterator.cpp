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
class BSTIterator {
private:
    stack<TreeNode*> st;
    void makeStack(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }
    void display(){
        stack<TreeNode*>disp = st;
        while(!disp.empty()){
            cout<<disp.top()->val<<" ";
            disp.pop();
        }
        cout<<endl;
    }

public:
    BSTIterator(TreeNode* root) {
        st = stack<TreeNode*>();
        makeStack(root);
    }

    int next() {
        display();
        TreeNode* curNode = st.top();
        st.pop();
        if (curNode->right != nullptr) {
            // st.push(curNode->right);
            makeStack(curNode->right);
        }
        // cout<<st.size()<<" ";
        return curNode->val;
    }

    bool hasNext() { return !st.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */