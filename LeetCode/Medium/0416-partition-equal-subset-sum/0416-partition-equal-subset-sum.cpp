class Solution {
private:
    vector<vector<int>> dp;
    bool dfs(vector<int>& nums, int idx, int sum) {
        if (sum == 0) {
            return true;
        }
        if (idx >= nums.size() || sum < 0) {
            return false;
        }
        if (dp[idx][sum] != -1) {
            return dp[idx][sum];
        }
        bool take = dfs(nums, idx + 1, sum - nums[idx]);
        bool skip = dfs(nums, idx + 1, sum);
        return dp[idx][sum] = take || skip;
    }

public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int x : nums) {
            total += x;
        }
        if (total % 2) {
            return false;
        }
        int target = total / 2;
        dp.assign(nums.size(), vector<int>(target + 1, -1));
        return dfs(nums, 0, target);
    }
};
