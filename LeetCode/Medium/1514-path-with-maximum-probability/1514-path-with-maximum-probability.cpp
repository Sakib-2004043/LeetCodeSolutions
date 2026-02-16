class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> best(n, 0.0);
        priority_queue<pair<double, int>> maxHeap;
        maxHeap.push({1.0, start_node});
        best[start_node] = 1.0;
        while (!maxHeap.empty()) {
            auto [prob, node] = maxHeap.top();
            maxHeap.pop();
            if (node == end_node) {
                return prob;
            }
            for (auto& [nextNode, edgeProb] : graph[node]) {
                double newProb = prob * edgeProb;
                if (newProb > best[nextNode]) {
                    best[nextNode] = newProb;
                    maxHeap.push({newProb, nextNode});
                }
            }
        }
        return 0.0;
    }
};
