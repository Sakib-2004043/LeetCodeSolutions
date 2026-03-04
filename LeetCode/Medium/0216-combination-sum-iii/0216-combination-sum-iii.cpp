class Solution {
private:
    vector<vector<int>> ans;
    void backTrack(vector<int> v, int tar, int sum, int k, int num) {
        if (k == -1 || num == 10 || sum > tar) {
            return;
        }
        if (k == 0 && sum == tar) {
            ans.push_back(v);
            return;
        }
        for (int i = num + 1; i < 10; i++) {
            v.push_back(i);
            backTrack(v, tar, sum + i, k - 1, i);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        backTrack(v, n, 0, k, 0);
        return ans;
    }
};