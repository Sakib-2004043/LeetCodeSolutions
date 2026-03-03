class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> v1, v2;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (auto num : nums1) {
            if (!binary_search(nums2.begin(), nums2.end(), num)) {
                v1.insert(num);
            }
        }
        for (auto num : nums2) {
            if (!binary_search(nums1.begin(), nums1.end(), num)) {
                v2.insert(num);
            }
        }
        return {vector<int>(v1.begin(), v1.end()),
                vector<int>(v2.begin(), v2.end())};
    }
};