class Solution {
private:
    int k;
    vector<vector<int>> ans;
    void getCombo(vector<int>& nums, int idx, vector<int>& combo) {
        if (combo.size() == k) {
            ans.push_back(combo);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            combo.push_back(nums[i]);
            getCombo(nums, i + 1, combo);
            combo.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combo;
        vector<int> nums;
        this->k = k;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        getCombo(nums, 0, combo);
        return ans;
    }
};