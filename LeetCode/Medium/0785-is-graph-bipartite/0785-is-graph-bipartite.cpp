class Solution {
private:
    bool check_dfs(auto& graph, auto& color, int node, int c) {
        bool ans = true;
        color[node] = c;
        for (auto nextNode : graph[node]) {
            if (color[nextNode] == -1) {
                ans &= check_dfs(graph, color, nextNode, 1 - c);
            } else if (color[nextNode] == c) {
                return false;
            }
        }
        return ans;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        bool ans = true;
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                ans &= check_dfs(graph, color, i, 0);
            }
        }
        return ans;
    }
};