class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i, n;
        n = nums.size();
        for (i = 0; i + k < n; i++) {
            if (nums[i] == nums[i + k]) {
                return true;
            }
        }
        return false;
    }
};