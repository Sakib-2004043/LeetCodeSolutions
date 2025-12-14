class Solution {
public:
    int dp[10010];
    int coinCounter(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (dp[amount] != -1) {
            return dp[amount];
        }
        int ans = INT_MAX;
        for (auto coin : coins) {
            if (amount - coin >= 0) {
                int res = coinCounter(coins, amount - coin);
                if (res != INT_MAX) {
                    ans = min(ans, res + 1);
                }
            }
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = coinCounter(coins, amount);
        ans = ans == INT_MAX ? -1 : ans;
        return ans;
    }
};