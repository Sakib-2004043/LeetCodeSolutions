class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++) {

            // 1-day pass
            int cost1 = costs[0] + (i > 0 ? dp[i - 1] : 0);

            // 7-day pass
            int j = i;
            while (j >= 0 && days[j] >= days[i] - 6) {
                j--;
            }
            int cost7 = costs[1] + (j >= 0 ? dp[j] : 0);

            // 30-day pass
            j = i;
            while (j >= 0 && days[j] >= days[i] - 29) {
                j--;
            }
            int cost30 = costs[2] + (j >= 0 ? dp[j] : 0);

            dp[i] = min({cost1, cost7, cost30});
        }

        return dp[n - 1];
    }
};
