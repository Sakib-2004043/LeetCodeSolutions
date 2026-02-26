class Solution {
private:
    int fee = 0;
    vector<vector<int>> dp;
    int dfs(auto& prices, int idx, int canBuy) {
        if (idx == prices.size()) {
            return 0;
        }
        if(dp[idx][canBuy] != -1){
            return dp[idx][canBuy];
        }
        if (canBuy) {
            int letBuy = dfs(prices, idx + 1, 0) - prices[idx];
            int notBuy = dfs(prices, idx + 1, 1);
            return dp[idx][canBuy] = max(letBuy, notBuy);
        }
        int letSell = dfs(prices, idx + 1, 1) + prices[idx] - fee;
        int notSell = dfs(prices, idx + 1, 0);
        return dp[idx][canBuy] = max(letSell, notSell);
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        this->fee = fee;
        dp.assign(prices.size(), vector<int>(2, -1));
        int ans = dfs(prices, 0, 1);
        return ans;
    }
};