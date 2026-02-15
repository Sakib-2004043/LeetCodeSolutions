class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> minHeap;
        vector<bool> visited(n, false);
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int manDis = abs(points[i][0] - points[j][0]);
                manDis += abs(points[i][1] - points[j][1]);
                graph[i].push_back({j, manDis});
                graph[j].push_back({i, manDis});
            }
        }
        minHeap.push({0, 0, -1});
        while (!minHeap.empty()) {
            auto [weight, node, parent] = minHeap.top();
            minHeap.pop();
            if (visited[node]) {
                continue;
            }
            ans += weight;
            visited[node] = true;
            for (auto nextNode : graph[node]) {
                minHeap.push({nextNode.second, nextNode.first, node});
            }
        }
        return ans;
    }
};