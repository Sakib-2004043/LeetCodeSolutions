class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq, freqFreq;
        for (auto x : arr) {
            freq[x]++;
        }
        for (auto [x, y] : freq) {
            if (freqFreq.count(y)){
                return false;
            }
            freqFreq[y]++;
        }
        return true;
    }
};