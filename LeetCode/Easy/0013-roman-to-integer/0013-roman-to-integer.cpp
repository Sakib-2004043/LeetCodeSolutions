class Solution {
public:
    unordered_map<char, int> roman = {{'I', 1},   {'V', 5},   {'X', 10},
                                      {'L', 50},  {'C', 100}, {'D', 500},
                                      {'M', 1000}};

    int romanToInt(string s) {
        int i, n, ans;
        n = s.size();
        ans = 0;
        for (i = n-1; i>=0; i--) {
            if (ans == 0) {
                ans += roman[s[i]];
            } else if (roman[s[i]] < roman[s[i + 1]]) {
                ans -= roman[s[i]];
            } else {
                ans += roman[s[i]];
            }
        }
        return ans;
    }
};