class Solution {
    vector<vector<string>> ans;
    void backTrack(string& s, vector<string>& vs, int idx) {
        if (idx == s.size()) {
            ans.push_back(vs);
        }
        int n = s.size();
        for (int i = idx; i < n; i++) {
            string as = s.substr(idx, i - idx + 1);
            string cs = as;
            reverse(cs.begin(), cs.end());
            if (as == cs) {
                vs.push_back(as);
                backTrack(s, vs, i + 1);
                vs.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> vs;
        backTrack(s, vs, 0);
        return ans;
    }
};