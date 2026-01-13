class Solution {
private:
    vector<int> dp;

public:
    Solution(){
        dp.assign(40,0);
    }
    int tribonacci(int n) {
        if (dp[n] != 0) {
            return dp[n];
        }
        if (n == 0 || n == 1 || n == 2) {
            return n == 2 ? 1 : n;
        }
        dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        return dp[n];
    }
};