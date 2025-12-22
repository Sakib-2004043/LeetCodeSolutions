class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        int bgn, end, mid, pos;
        bgn = 0, pos = -1;
        end = nums.size() - 1;
        while (bgn <= end) {
            mid = bgn + (end - bgn) / 2;
            if (nums[mid] == target) {
                pos = mid;
                break;
            }
            if (target < nums[mid]) {
                end = mid - 1;
            } else {
                bgn = mid + 1;
            }
        }
        if(pos==-1){
            return ans;
        }
        if(nums[0]==target){
            ans[0]=0;
            goto ff;
        }
        bgn = 0;
        end = pos;
        while (bgn <= end) {
            mid = bgn + (end - bgn) / 2;
            if (nums[mid] != target && nums[mid + 1] == target) {
                ans[0] = mid + 1;
                break;
            }
            if (nums[mid] == target) {
                end = mid - 1;
            } else
                bgn = mid + 1;
        }
        ff:;
        if(nums[nums.size()-1]==target){
            ans[1]=nums.size()-1;
            goto ss;
        }
        bgn = pos;
        end = nums.size()-1;
        while (bgn <= end) {
            mid = bgn + (end - bgn) / 2;
            mid = mid ? mid:1;
            if (nums[mid-1] == target && nums[mid] != target) {
                ans[1] = mid-1;
                break;
            }
            if (nums[mid] == target) {
                bgn = mid + 1;
            } else
                end = mid - 1;
        }
        ss:;
        return ans;
    }
};