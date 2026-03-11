class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, mul = 1;
        int n = nums.size();
        int i = 0, j = 0, z = 0;
        while (i < n) {
            j = i;
            while (i < n && nums[i]) {
                mul *= nums[i];
                ans = max(ans, mul);
                i++;
            }
            while (j < i - 1) {
                mul /= nums[j];
                ans = max(ans, mul);
                j++;
            }
            if (i < n && nums[i] == 0) {
                i++;
                mul = 1;
                z = 1;
            }
        }
        return (z && ans < 0) ? 0 : ans;
    }
};