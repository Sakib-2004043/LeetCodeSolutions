class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i, j;
        vector<int> v;
        if (n == 0) {
            goto finish;
        } else if (m == 0) {
            nums1 = nums2;
            goto finish;
        }
        i = 0;
        j = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                v.push_back(nums1[i]);
                i++;
            } else {
                v.push_back(nums2[j]);
                j++;
            }
        }
        while (i < m) {
            v.push_back(nums1[i++]);
        }
        while (j < n) {
            v.push_back(nums2[j++]);
        }

        nums1 = v;
    finish:;
    }
};