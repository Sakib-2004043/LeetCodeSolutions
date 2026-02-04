class Solution {
public:
    bool wordBreak(string s, vector<string>& wd) {
        // int maxLen = 0;
        // for (auto& word : wd) {
        //     maxLen = max(maxLen, (int)word.size());
        // }
        int n = s.size();
        sort(wd.begin(), wd.end());
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0 ; j--) {
                string subString = s.substr(j, i - j);
                bool found = binary_search(wd.begin(), wd.end(), subString);
                if (found && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};