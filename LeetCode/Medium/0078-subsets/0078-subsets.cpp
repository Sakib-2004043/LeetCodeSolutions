class Solution {
private:
    vector<vector<int>> ans;
    void backTrack(vector<int>& nums, vector<int>& subSet, int idx) {
        ans.push_back(subSet);
        for (int i = idx; i < nums.size(); i++) {
            subSet.push_back(nums[i]);
            backTrack(nums, subSet, i + 1);
            subSet.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subSet;
        backTrack(nums, subSet, 0);
        return ans;
    }
};