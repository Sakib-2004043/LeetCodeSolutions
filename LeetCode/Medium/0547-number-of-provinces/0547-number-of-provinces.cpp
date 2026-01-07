class Solution {
private:
    vector<bool> visited;
    void bfs(vector<vector<int>>& graph, int idx) {
        queue<int> connection;
        connection.push(idx);
        while (!connection.empty()) {
            int row = connection.front();
            for (int i = 0; i < graph.size(); i++) {
                if (!visited[i] && graph[row][i]) {
                    visited[i] = true;
                    connection.push(i);
                }
            }
            connection.pop();
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        visited.assign(n + 5, false);
        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                provinces++;
                bfs(isConnected, i);
            }
        }
        return provinces;
    }
};