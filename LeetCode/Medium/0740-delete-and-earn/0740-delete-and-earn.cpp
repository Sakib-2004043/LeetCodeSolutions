class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> points(10001, 0);
        for (int x : nums) {
            points[x] += x;
        }
        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]
        for (int i = 0; i <= 10000; i++) {
            int curr = max(prev1, prev2 + points[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
