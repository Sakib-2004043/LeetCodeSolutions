class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            sum -= (i >= k) ? nums[i - k] : 0;
            if (i + 1 >= k) {
                mx = max(mx, sum);
            }
        }
        return mx * 1.0 / k;
    }
};