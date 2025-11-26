class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i, k, n;
        n = nums.size();
        k = nums[0];
        for (i = 1; i < n; i++) {
            k--;
            if (k < 0) {
                return false;
            }
            k = max(k, nums[i]);
        }
        return true;
    }
};