class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using T = tuple<int, int>;
        priority_queue<T, vector<T>, greater<T>> minHeap;
        vector<int> minDis(n + 1, INT_MAX);
        vector<vector<T>> graph(n + 1);
        for (auto x : times) {
            graph[x[0]].push_back({x[1], x[2]});
        }
        minDis[k] = 0;
        minHeap.push({0, k});
        while (!minHeap.empty()) {
            auto [cost, node] = minHeap.top();
            minHeap.pop();
            minDis[node] = min(minDis[node], cost);
            for (auto [nextNode, nextCost] : graph[node]) {
                if (cost + nextCost < minDis[nextNode]) {
                    minHeap.push({cost + nextCost, nextNode});
                }
            }
        }
        int ans = *max_element(minDis.begin() + 1, minDis.end());
        return ans != INT_MAX ? ans : -1;
    }
};