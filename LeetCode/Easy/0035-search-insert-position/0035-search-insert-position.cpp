class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int bgn, end, mid;
        bgn = 0;
        end = nums.size() - 1;
        
        while (bgn <= end) {
            mid = bgn + (end - bgn) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                bgn = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return bgn;
    }
};