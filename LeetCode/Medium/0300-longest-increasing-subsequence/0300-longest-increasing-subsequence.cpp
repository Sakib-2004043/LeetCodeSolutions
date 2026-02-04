class Solution {
private:
    vector<int> dp;
    int dfs(vector<int>& nums, int idx) {
        if(dp[idx]){
            return dp[idx];
        }
        int count = 0;
        for (int i = idx + 1; i < nums.size(); i++) {
            if (nums[idx] < nums[i]) {
                count = max(count, dfs(nums, i));
            }
        }
        return dp[idx] = count + 1;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        dp.assign(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, dfs(nums, i));
        }
        return ans;
    }
};