class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& e : flights) {
            graph[e[0]].push_back({e[1], e[2]});
        }
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> minHeap;
        minHeap.push({0, src, 0});
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;
        while (!minHeap.empty()) {
            auto [cost, node, stops] = minHeap.top();
            minHeap.pop();
            if (node == dst) {
                return cost;
            }
            if (stops > k) {
                continue;
            }
            for (auto& [nextNode, price] : graph[node]) {
                int newCost = cost + price;
                if (newCost < dist[nextNode][stops + 1]) {
                    dist[nextNode][stops + 1] = newCost;
                    minHeap.push({newCost, nextNode, stops + 1});
                }
            }
        }
        return -1;
    }
};
