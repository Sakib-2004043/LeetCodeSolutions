class Solution {
private:
    vector<int> state; // 0 = unknown, 1 = safe, 2 = unsafe
    vector<bool> inCurrentPath;

    bool dfs(vector<vector<int>>& graph, int node) {
        if (state[node] != 0) {
            return state[node] == 1;
        }
        if (inCurrentPath[node]) {
            state[node] = 2; // cycle detected
            return false;
        }
        inCurrentPath[node] = true;
        bool isSafe = true;
        for (int nextNode : graph[node]) {
            isSafe &= dfs(graph, nextNode);
        }
        inCurrentPath[node] = false;
        state[node] = isSafe ? 1 : 2;
        return isSafe;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        state.assign(n, 0);
        inCurrentPath.assign(n, false);
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (dfs(graph, i)) {
                result.push_back(i);
            }
        }
        return result;
    }
};
