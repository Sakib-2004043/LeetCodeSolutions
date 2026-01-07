class Solution {
private:
    vector<vector<int>> graph;
    vector<bool> visited;
    void bfs(int idx) {
        queue<vector<int>> connection;
        connection.push(graph[idx]);
        while (!connection.empty()) {
            int n = connection.front().size();
            for (int i = 0; i < n; i++) {
                if (!visited[i] && connection.front()[i]) {
                    visited[i] = true;
                    connection.push(graph[i]);
                }
            }
            connection.pop();
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        this->graph = isConnected;
        int n = isConnected.size();
        visited.assign(n + 5, false);
        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                provinces++;
                bfs(i);
            }
        }
        return provinces;
    }
};