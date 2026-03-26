class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (find(nums.begin(), nums.end(), 1) == nums.end()) {
            return 1;
        }
        // Normalize invalid values
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }
        // Marking
        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            nums[idx] = -abs(nums[idx]);
        }
        // Find answer
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
