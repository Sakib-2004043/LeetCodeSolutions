class Solution {
private:
    unordered_set<string> visited;
    double dfs(auto& graph, string cur, string tar) {
        if (cur == tar) {
            return 1.0;
        }
        visited.insert(cur);
        for (auto nextStr : graph[cur]) {
            if (!visited.count(nextStr.first)) {
                double ans = dfs(graph, nextStr.first, tar);
                if (ans != -1) {
                    return ans * nextStr.second;
                }
            }
        }
        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        int n = values.size();
        vector<double> ans;
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < n; i++) {
            string lob = equations[i][0];
            string hor = equations[i][1];
            graph[lob][hor] = values[i];
            graph[hor][lob] = 1.0 / values[i];
        }
        for (auto query : queries) {
            string lob = query[0];
            string hor = query[1];
            if (!graph.count(lob) || !graph.count(hor)) {
                ans.push_back(-1.0);
            } else {
                visited.clear();
                ans.push_back(dfs(graph, lob, hor));
            }
        }
        return ans;
    }
};