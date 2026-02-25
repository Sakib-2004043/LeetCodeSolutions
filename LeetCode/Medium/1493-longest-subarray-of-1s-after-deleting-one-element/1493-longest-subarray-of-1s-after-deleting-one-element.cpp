class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int z = 0, ans = 0;
        int i = 0, j = 0, k = 1;
        while (i < n) {
            z += nums[i] ? 0 : 1;
            while (j < n && z > k) {
                z -= nums[j] ? 0 : 1;
                j++;
            }
            ans = max(ans, i++ - j);
        }
        return ans;
    }
};