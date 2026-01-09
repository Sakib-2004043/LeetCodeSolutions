class Solution {
private:
    vector<vector<int>> ans;
    void dfs(auto& graph, auto& result, int node) {
        if (node == graph.size() - 1) {
            ans.push_back(result);
        }
        for (auto nextNode : graph[node]) {
            result.push_back(nextNode);
            dfs(graph, result, nextNode);
            result.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> result;
        result.push_back(0);
        dfs(graph, result, 0);
        return ans;
    }
};