class Solution {
public:
    int findMin(vector<int>& nums) {
        int bgn, mid, end;
        bgn = 0;
        end = nums.size() - 1;
        while (bgn < end) {
            mid = bgn + (end - bgn) / 2;
            if (nums[mid] > nums[end]) {
                bgn = mid+1;
            } else {
                end = mid ;
            }
        }
        return nums[bgn];
    }
};