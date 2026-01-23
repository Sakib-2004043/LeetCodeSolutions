class Solution {
public:
    int numSquares(int n) {
        vector<int> prime;
        for (int i = 1; i * i <= n; i++) {
            prime.push_back(i * i);
        }
        vector<int> dp(n + 5, 0);
        for (int i = 1; i <= n; i++) {
            if ((int)sqrt(i) * (int)sqrt(i) == i) {
                dp[i] = 1;
                continue;
            }
            int mn = INT_MAX;
            for (int j = 0; j < prime.size() && prime[j] < i; j++) {
                mn = min(mn, dp[prime[j]] + dp[i - prime[j]]);
            }
            dp[i] = mn;
        }
        return dp[n];
    }
};