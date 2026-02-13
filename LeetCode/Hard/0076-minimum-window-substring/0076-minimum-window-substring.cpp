class Solution {
private:
    bool isValid(vector<int>& cur, vector<int>& tar) {
        for (int i = 0; i < 128; i++) {
            if (cur[i] < tar[i])
                return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        vector<int> tar(128);
        vector<int> cur(128);
        for (char c : t) {
            tar[c]++;
        }
        int i = 0, j = 0, n = s.size();
        int start = 0, minLen = INT_MAX;
        while (i < n) {
            cur[s[i]]++;

            while (isValid(cur, tar)) {
                if (i - j + 1 < minLen) {
                    minLen = i - j + 1;
                    start = j;
                }
                cur[s[j]]--;
                j++;
            }
            i++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
