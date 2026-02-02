class Solution {
private:
    queue<pair<int, int>> idxVal;
    vector<int> w;

public:
    Solution(vector<int>& w) {
        for (int i = 0; i < w.size(); i++) {
            idxVal.push({i, w[i]});
        }
        this->w = w;
    }

    int pickIndex() {
        auto [idx, val] = idxVal.front();
        val--;
        if (val == 0) {
            idxVal.pop();
            idxVal.push({idx, w[idx]});
        }else{
            idxVal.front().second = val;
        }
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */