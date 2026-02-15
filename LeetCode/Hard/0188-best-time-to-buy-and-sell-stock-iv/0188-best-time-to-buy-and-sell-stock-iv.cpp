class Solution {
private:
    vector<vector<vector<int>>> dp;
    int calcDFS(vector<int>& prices, int idx, int canBuy, int count) {
        if (count == 0 || idx == prices.size()) {
            return 0;
        }
        if (dp[idx][canBuy][count] != -1) {
            return dp[idx][canBuy][count];
        }
        if (canBuy == 1) {
            int canBuySTC = calcDFS(prices, idx + 1, 0, count) - prices[idx];
            int notcanBuy = calcDFS(prices, idx + 1, 1, count);
            return dp[idx][canBuy][count] = max(canBuySTC, notcanBuy);
        }
        int notSell = calcDFS(prices, idx + 1, 0, count);
        int sellSTC = calcDFS(prices, idx + 1, 1, count - 1) + prices[idx];
        return dp[idx][canBuy][count] = max(sellSTC, notSell);
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        dp.assign(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));
        int ans = calcDFS(prices, 0, 1, k);
        return ans;
    }
};