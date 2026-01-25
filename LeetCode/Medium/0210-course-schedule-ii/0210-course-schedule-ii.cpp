class Solution {
private:
    vector<int> topoCourse;
    vector<bool> visited;
    vector<bool> inStack;
    bool isCycle = false;
    void topoSortDFS(auto& graph, int node) {
        if (isCycle) {
            return;
        }
        if (visited[node]) {
            return;
        }
        visited[node] = true;
        inStack[node] = true;
        for (auto nextNode : graph[node]) {
            if (inStack[nextNode]) {
                isCycle = true;
            }
            if (!visited[nextNode]) {
                topoSortDFS(graph, nextNode);
            }
        }
        topoCourse.push_back(node);
        inStack[node] = false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& e : prerequisites) {
            graph[e[1]].push_back(e[0]);
        }
        visited.assign(numCourses, false);
        inStack.assign(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            topoSortDFS(graph, i);
        }
        if (isCycle) {
            topoCourse = {};
        }
        reverse(topoCourse.begin(), topoCourse.end());
        return topoCourse;
    }
};