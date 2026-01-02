class Solution {
private:
    vector<vector<int>> ans;
    vector<int> candidates;
    int target;
    void sumTerget(vector<int>& combo, int sum, int idx) {
        if (sum == target) {
            ans.push_back(combo);
        } else if (sum > target) {
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            combo.push_back(candidates[i]);
            sumTerget(combo, sum + candidates[i], i);
            combo.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;
        this->candidates = candidates;
        vector<int> combo;
        sumTerget(combo, 0, 0);
        return ans;
    }
};