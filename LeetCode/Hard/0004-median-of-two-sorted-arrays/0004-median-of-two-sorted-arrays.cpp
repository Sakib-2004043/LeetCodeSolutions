class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> nums;
        int i = 0, j = 0;
        while (i < n1 || j < n2) {
            if (i < n1 && j < n2 && nums1[i] <= nums2[j]) {
                nums.push_back(nums1[i++]);
            } else {
                nums.push_back(j < n2 ? nums2[j++] : nums1[i++]);
            }
        }
        double ans = 0;
        if ((n1 + n2) % 2 == 1) {
            ans = nums[(n1 + n2) / 2];
        } else {
            ans = (nums[(n1 + n2) / 2] + nums[(n1 + n2) / 2 - 1]) * 0.5;
        }
        return ans;
    }
};