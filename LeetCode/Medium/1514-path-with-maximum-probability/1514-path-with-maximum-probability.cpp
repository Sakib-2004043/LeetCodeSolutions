class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        int sz = edges.size();
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < sz; i++) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        unordered_map<int, unordered_map<int, double>> dp;
        using T = tuple<double, int>;
        priority_queue<T> maxHeap;
        maxHeap.push({0.0, start_node});
        while (!maxHeap.empty()) {
            auto [prob, node] = maxHeap.top();
            maxHeap.pop();
            if (node == end_node) {
                return prob;
            }
            for (auto [nextNode, newProb] : graph[node]) {
                double nextProb = prob != 0.0 ? prob * newProb : newProb;
                if (dp[node][nextNode] < nextProb) {
                    maxHeap.push({nextProb, nextNode});
                    dp[node][nextNode] = nextProb;
                }
            }
        }
        return 0.0;
    }
};