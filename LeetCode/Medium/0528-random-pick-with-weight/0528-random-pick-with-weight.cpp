class Solution {
private:
    vector<int> w;
    int total_sum;

public:
    Solution(vector<int>& w) {
        for (int i = 1; i < w.size(); i++) {
            w[i] += w[i - 1];
        }
        total_sum = w.back();
        this->w = w;
    }

    int pickIndex() {
        int r = rand() % total_sum;
        for (int i = 0; i < w.size(); i++) {
            if (w[i] > r) {
                return i;
            }
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */