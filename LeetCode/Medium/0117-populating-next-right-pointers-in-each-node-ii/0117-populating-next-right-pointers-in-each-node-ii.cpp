/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return NULL;
        }
        int i, n, sz;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {  
            sz = q.size();
            while (sz--) {
                Node* curNode = q.front();
                q.pop();
                if (!q.empty() && sz) {
                    curNode->next = q.front();
                } else {
                    curNode->next = NULL;
                }
                if (curNode->left != nullptr) {
                    q.push(curNode->left);
                }
                if (curNode->right != nullptr) {
                    q.push(curNode->right);
                }
            }
        }
        return root;
    }
};