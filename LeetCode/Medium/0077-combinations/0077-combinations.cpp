class Solution {
private:
    int k, n;
    vector<vector<int>> ans;
    void getCombo(int idx, vector<int>& combo) {
        if (combo.size() == k) {
            ans.push_back(combo);
            return;
        }
        for (int i = idx; i <= n; i++) {
            combo.push_back(i);
            getCombo(i + 1, combo);
            combo.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combo;
        this->k = k;
        this->n = n;
        getCombo(1, combo);
        return ans;
    }
};