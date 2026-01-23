class Solution {
public:
    int numSquares(int n) {
        // Generate all perfect squares <= n
        vector<int> squares;
        for (int i = 1; i * i <= n; i++)
            squares.push_back(i * i);

        // dp[i] = minimum number of perfect squares summing to i
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0; // base case
        for (int i = 1; i <= n; i++) {
            for (int sq : squares) {
                if (sq > i) {
                    break;
                }
                dp[i] = min(dp[i], 1 + dp[i - sq]);
            }
        }
        return dp[n];
    }
};
