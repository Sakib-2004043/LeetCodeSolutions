class Solution {
private:
    void getCombo(int idx, int n, int k, vector<int>& combo, vector<vector<int>>& ans) {
        if (combo.size() == k) {
            ans.push_back(combo);
            return;
        }
        for (int i = idx; i <= n; i++) {
            combo.push_back(i);
            getCombo(i + 1, n, k, combo, ans);
            combo.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combo;
        vector<vector<int>> ans;
        getCombo(1, n, k, combo, ans);
        return ans;
    }
};
