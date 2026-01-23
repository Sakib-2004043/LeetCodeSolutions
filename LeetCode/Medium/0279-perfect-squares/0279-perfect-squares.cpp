class Solution {
private:
    vector<int> dp;

public:
    Solution() {
        const int N = 1e4 + 1;
        dp.assign(N, 0);
        vector<int> prime;
        for (int i = 1; i * i < N - 5; i++) {
            prime.push_back(i * i);
        }
        for (int i = 1; i < N; i++) {
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
    }
    int numSquares(int n) { return dp[n]; }
};