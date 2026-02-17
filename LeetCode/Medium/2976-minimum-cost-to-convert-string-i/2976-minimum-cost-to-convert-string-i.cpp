class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& costs) {
        const long long INF = 1e15;
        vector<vector<long long>> minCost(26, vector<long long>(26, INF));

        // initialize self cost = 0
        for (int i = 0; i < 26; i++) {
            minCost[i][i] = 0;
        }
        // fill direct edges
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            minCost[u][v] = min(minCost[u][v], (long long)costs[i]);
        }
        // Floyd–Warshall
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (minCost[i][k] < INF && minCost[k][j] < INF) {
                        long long viaCost = minCost[i][k] + minCost[k][j];
                        minCost[i][j] = min(minCost[i][j], viaCost);
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            long long cost = minCost[source[i] - 'a'][target[i] - 'a'];
            if (cost == INF) {
                return -1;
            }
            ans += cost;
        }
        return ans;
    }
};
