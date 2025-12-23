class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, mx, mn, n, ans;
        n = prices.size();
        mx = prices[0];
        mn = prices[0];
        ans = 0;
        for (i = 1; i < n; i++) {
            if (mn > prices[i]) {
                mn = prices[i];
                mx = 0;
            }
            mx = max(mx, prices[i]);
            ans = max(ans, mx - mn);
        }
        return ans;
    }
};