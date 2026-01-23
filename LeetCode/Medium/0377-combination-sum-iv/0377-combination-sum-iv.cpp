class Solution {
private:
    vector<int> dp;

    int dfs_sum(vector<int>& nums, int target, int sum) {
        if (sum >= target) {
            return sum == target ? 1 : 0;
        }
        if (dp[sum] != -1) {
            return dp[sum];
        }
        int ways = 0;
        for (int num : nums) {
            ways += dfs_sum(nums, target, sum + num);
        }
        return dp[sum] = ways;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        dp.assign(target + 1, -1);
        return dfs_sum(nums, target, 0);
    }
};
