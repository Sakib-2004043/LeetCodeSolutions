class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(n);
        int ans = -1;
        preSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            preSum[i] += preSum[i - 1] + nums[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            nums[i] += (i + 1 < n) ? nums[i + 1] : 0;
            if (preSum[i] == nums[i]) {
                ans = i;
            }
        }
        return ans;
    }
};