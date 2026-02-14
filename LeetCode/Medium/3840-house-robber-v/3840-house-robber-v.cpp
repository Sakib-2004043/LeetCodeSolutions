class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        long long pre2 = nums[0];
        long long pre1 =
            colors[0] == colors[1] ? max(nums[0], nums[1]) : nums[0] + nums[1];
        for (int i = 2; i < n; i++) {
            long long now = 0;
            if (colors[i - 1] == colors[i]) {
                now = max(pre1, pre2 + nums[i]);
            } else {
                now = pre1 + nums[i];
            }
            pre2 = pre1;
            pre1 = now;
        }
        return pre1;
    }
};