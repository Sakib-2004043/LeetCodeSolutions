class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> unique;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    vector<int> triplet = {nums[i], nums[left], nums[right]};
                    unique.insert(triplet);
                    left++, right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        // copy set to vector
        vector<vector<int>> ans;
        for (auto& v : unique)
            ans.push_back(v);
        return ans;
    }
};
