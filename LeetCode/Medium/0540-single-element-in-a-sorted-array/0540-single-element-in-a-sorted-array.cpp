class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int left = 0, right = n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            // make mid even so we can safely compare mid & mid+1
            if (mid % 2 == 1)
                mid--;
            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};
