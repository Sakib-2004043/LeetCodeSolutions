class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i, n, ans, sum;
        n = nums.size();
        ans = sum = nums[0];

        for (i = 1; i < n; i++) {
            sum = max(nums[i], sum + nums[i]);
            ans = max(ans, sum);
        }
        return ans;
    }
};
