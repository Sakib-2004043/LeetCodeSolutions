class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s_to_t;
        unordered_map<char, char> t_to_s;
        for (int i = 0; i < s.size(); i++) {
            if (!s_to_t.count(s[i])) {
                s_to_t[s[i]] = t[i];
            } else if (s_to_t[s[i]] != t[i]) {
                return false;
            }
            if (!t_to_s.count(t[i])) {
                t_to_s[t[i]] = s[i];
            } else if (t_to_s[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};