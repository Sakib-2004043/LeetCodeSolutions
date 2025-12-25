class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, n, buy, ans;
        n = prices.size();
        ans = 0, buy = prices[0];
        for (i = 1; i < n; i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else {
                ans = ans + prices[i] - buy;
                buy = prices[i];
            }
        }
        return ans;
    }
};