class Solution {
public:
    int climbStairs(int n) {
        int i, sum[50];
        sum[1] = 1;
        sum[2] = 2;
        for (i = 3; i <= n; i++) {
            sum[i] = sum[i - 1] + sum[i - 2];
        }
        return sum[n];
    }
};