class Solution {
public:
    int search(vector<int>& nums, int target) {
        int bgn = 0, end = nums.size() - 1, mid;
        while (bgn <= end) {
            mid = bgn + (end - bgn) / 2;
            if (nums[mid] == target)
                return mid;
            // Check if left half is sorted
            if (nums[bgn] <= nums[mid]) {
                // target in left half
                if (target >= nums[bgn] && target < nums[mid])
                    end = mid - 1;
                else
                    bgn = mid + 1;
            }
            // Otherwise, right half must be sorted
            else {
                // target in right half
                if (target > nums[mid] && target <= nums[end])
                    bgn = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
};
