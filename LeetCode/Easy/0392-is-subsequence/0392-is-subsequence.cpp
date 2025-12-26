class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0;
        for (int i = 0; i < t.size(); i++) {
            if (j < s.size() && t[i] == s[j]) {
                j++;
            }
        }
        cout<<j;
        return j == s.size();
    }
};