class Solution {
private:
    vector<bool> visited;
    vector<bool> inStack;

    void cycle_check_dfs(vector<vector<int>>& graph, int node, bool& ans) {
        if (!ans) {
            return;
        }
        if (visited[node]) {
            return;
        }
        visited[node] = true;
        inStack[node] = true;
        for (auto nextNode : graph[node]) {
            if (inStack[nextNode]) {
                ans = false;
                return;
            }
            cycle_check_dfs(graph, nextNode, ans);
        }
        inStack[node] = false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& e : prerequisites) {
            graph[e[1]].push_back(e[0]);
        }
        visited.assign(numCourses, false);
        inStack.assign(numCourses, false);
        bool ans = true;
        for (int i = 0; i < numCourses && ans; i++) {
            cycle_check_dfs(graph, i, ans);
        }
        return ans;
    }
};
