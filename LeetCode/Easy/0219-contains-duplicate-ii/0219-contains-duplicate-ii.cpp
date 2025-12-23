class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i, n;
        unordered_map<int, int> mp;
        n = nums.size();
        for (i = 0; i < n; i++) {
            if (mp[nums[i]] && (i - mp[nums[i]]) < k) {
                return true;
            }
            mp[nums[i]] = i + 1;
        }
        return false;
    }
};