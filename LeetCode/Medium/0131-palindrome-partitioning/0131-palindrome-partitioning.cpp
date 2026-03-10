class Solution {
private:
    vector<vector<string>> ans;
    bool isPal(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    void backTrack(string& s, vector<string>& cur, int idx) {
        if (idx == s.size()) {
            ans.push_back(cur);
        }
        for (int i = idx; i < s.size(); i++) {
            if (isPal(s, idx, i)) {
                cur.push_back(s.substr(idx, i - idx + 1));
                backTrack(s, cur, i + 1);
                cur.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        backTrack(s, cur, 0);
        return ans;
    }
};
