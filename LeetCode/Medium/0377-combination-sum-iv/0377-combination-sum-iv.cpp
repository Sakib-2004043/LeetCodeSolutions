class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int x = 1; x <= target; x++) {
            for (int num : nums) {
                if (x >= num) {
                    dp[x] += dp[x - num];
                }
            }
        }
        return dp[target];
    }
};