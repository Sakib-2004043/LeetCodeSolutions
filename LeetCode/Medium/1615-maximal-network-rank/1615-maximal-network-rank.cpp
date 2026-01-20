class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<vector<bool>> adj(n, vector<bool>(n, false));
        for (auto& road : roads) {
            int u = road[0], v = road[1];
            degree[u]++;
            degree[v]++;
            adj[u][v] = true;
            adj[v][u] = true;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int networkRank = degree[i] + degree[j] - (adj[i][j] ? 1 : 0);
                ans = max(ans, networkRank);
            }
        }
        return ans;
    }
};
