class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxSum = nums[0], curMax = 0;
        int minSum = nums[0], curMin = 0;
        for (auto num : nums) {
            curMax = max(num, curMax + num);
            maxSum = max(maxSum, curMax);
            curMin = min(num, curMin + num);
            minSum = min(minSum, curMin);
            totalSum += num;
        }
        return maxSum < 0 ? maxSum : max(maxSum, totalSum - minSum);
    }
};