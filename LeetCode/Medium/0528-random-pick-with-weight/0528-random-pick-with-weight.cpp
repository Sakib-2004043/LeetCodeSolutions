class Solution {
private:
    vector<int> w;

public:
    Solution(vector<int>& w) {
        for (int i = 1; i < w.size(); i++) {
            w[i] += w[i - 1];
        }
        this->w = w;
    }

    int pickIndex() {
        int randVal = rand() % w.back();
        int idx = upper_bound(w.begin(), w.end(), randVal) - w.begin();
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */