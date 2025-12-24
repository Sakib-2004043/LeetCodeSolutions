/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0), neighbors(vector<Node*>()) {}
    Node(int _val) : val(_val), neighbors(vector<Node*>()) {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // Mapping original node value → cloned node pointer
        map<int, Node*> cloneMap;

        // BFS queue
        queue<Node*> q;

        // Step 1: Create all nodes (structure only, no neighbors)
        q.push(node);
        cloneMap[node->val] = new Node(node->val);

        vector<bool> visited(200, false);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            visited[curr->val] = true;

            for (Node* nei : curr->neighbors) {
                if (!visited[nei->val]) {
                    if (!cloneMap.count(nei->val)) {
                        cloneMap[nei->val] = new Node(nei->val);
                    }
                    q.push(nei);
                    visited[nei->val] = true;
                }
            }
        }

        // Step 2: Connect neighbors
        fill(visited.begin(), visited.end(), false);
        q.push(node);
        visited[node->val] = true;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (Node* nei : curr->neighbors) {
                cloneMap[curr->val]->neighbors.push_back(cloneMap[nei->val]);
                if (!visited[nei->val]) {
                    visited[nei->val] = true;
                    q.push(nei);
                }
            }
        }

        return cloneMap[node->val];
    }
};
