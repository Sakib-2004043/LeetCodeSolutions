class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        if (nums[0] > nums[1]) {
            return 0;
        }
        if (nums[nums.size() - 1] > nums[nums.size() - 2]) {
            return nums.size() - 1;
        }
        int i, bgn, mid, end;
        bgn = 1;
        end = nums.size() - 2;
        mid = bgn + (end - bgn) / 2;
        while (bgn <= end) {
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            if (nums[mid - 1] > nums[mid]) {
                end = mid - 1;
                mid = bgn + (end - bgn) / 2;
            } else {
                bgn = mid + 1;
                mid = bgn + (end - bgn) / 2;
            }
        }
        return 0;
    }
};