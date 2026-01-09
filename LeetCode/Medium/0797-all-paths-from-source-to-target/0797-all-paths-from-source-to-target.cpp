class Solution {
private:
    void dfs(auto& graph, auto& ans, auto& result, int node) {
        if (node == graph.size() - 1) {
            ans.push_back(result);
        }
        for (auto nextNode : graph[node]) {
            result.push_back(nextNode);
            dfs(graph, ans, result, nextNode);
            result.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> result;
        vector<vector<int>> ans;
        result.push_back(0);
        dfs(graph, ans, result, 0);
        return ans;
    }
};