/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }

        map<int, Node*> mp;
        queue<Node*> q;
        vector<bool> visited(200, false);

        q.push(node);

        Node* newNode = new Node();
        newNode->val = node->val;
        mp[node->val] = newNode;

        while (!q.empty()) {
            Node* curNode = NULL;
            curNode = q.front();
            q.pop();
            visited[curNode->val] = true;
            for (auto x : curNode->neighbors) {
                if (!visited[x->val]) {
                    q.push(x);
                    Node* newNode = new Node();
                    newNode->val = x->val;
                    mp[x->val] = newNode;
                }
            }
        }

        q.push(node);
        fill(visited.begin(), visited.end(), false);

        while (!q.empty()) {
            Node* curNode = NULL;
            curNode = q.front();
            q.pop();
            visited[curNode->val] = true;
            for (auto x : curNode->neighbors) {
                if (!visited[x->val]) {
                    visited[x->val] = true;
                    q.push(x);
                }
                
                // cout<<curNode->val<<"--==>>"<<x->val<<endl;
                mp[curNode->val]->neighbors.push_back(mp[x->val]);
            }
            // cout<<curNode->val<<"--Neig Size==>>"<<mp[curNode->val]->neighbors.size()<<endl;
        }

        // cout << mp.size();
        // Node* dummy = new Node();
        return mp[node->val];
    }
};