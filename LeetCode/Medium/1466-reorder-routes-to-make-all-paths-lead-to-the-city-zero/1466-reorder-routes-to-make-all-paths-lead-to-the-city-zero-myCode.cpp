class Solution {
private:
    map<pair<int, int>, bool> direction;
    vector<bool> visited;
    int ans = 0;
    void dfs(vector<vector<int>>& graph, int node) {
        visited[node] = true;
        for (auto& nextNode : graph[node]) {
            if (!visited[nextNode] && direction[{node, nextNode}]) {
                ans++;
            }
            if (!visited[nextNode]) {
                dfs(graph, nextNode);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        visited.assign(n, false);
        for (auto& edge : connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            direction[{edge[0], edge[1]}] = true;
        }
        dfs(graph, 0);
        return ans;
    }
};