class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int z = 0, ans = 0;
        int i = 0, j = 0;
        while (i < n) {
            if (nums[i] == 0) {
                z++;
            }
            while (j < n && z > k) {
                if (nums[j] == 0) {
                    z--;
                }
                j++;
            }
            ans = max(ans, i - j + 1);
            i++;
        }
        return ans;
    }
};