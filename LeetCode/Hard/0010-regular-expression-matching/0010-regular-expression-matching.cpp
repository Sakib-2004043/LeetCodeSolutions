class Solution {
public:
    bool solve(int i, int j, string &s, string &p) {
        // If pattern is finished
        if (j == p.size()) {
            return i == s.size();
        }

        // Check current character match
        bool firstMatch = (i < s.size()) &&
                          (s[i] == p[j] || p[j] == '.');

        // If next char is '*'
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // zero occurrence OR one/more occurrence
            return solve(i, j + 2, s, p) ||
                   (firstMatch && solve(i + 1, j, s, p));
        } 
        // Normal case
        else {
            return firstMatch && solve(i + 1, j + 1, s, p);
        }
    }

    bool isMatch(string s, string p) {
        return solve(0, 0, s, p);
    }
};
