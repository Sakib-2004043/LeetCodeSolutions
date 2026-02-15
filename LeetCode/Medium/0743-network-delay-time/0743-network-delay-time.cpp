class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using T = tuple<int, int>;
        priority_queue<T, vector<T>, greater<T>> minHeap;
        vector<int> minDis(n + 1, INT_MAX);
        vector<vector<T>> graph(n + 1);
        vector<bool> visited(n + 1, false);
        for (auto x : times) {
            graph[x[0]].push_back({x[1], x[2]});
        }
        minDis[k] = 0;
        minHeap.push({0, k});
        while (!minHeap.empty()) {
            auto [cost, node] = minHeap.top();
            minHeap.pop();
            if (visited[node]) {
                continue;
            }
            visited[node] = true;
            minDis[node] = min(minDis[node], cost);
            for (auto [nextNode, nextCost] : graph[node]) {
                if (!visited[nextNode]) {
                    minHeap.push({cost + nextCost, nextNode});
                }
            }
        }
        int ans = *max_element(minDis.begin() + 1, minDis.end());
        return ans != INT_MAX ? ans : -1;
    }
};