class Solution {
private:
    vector<vector<int>> dp;
    int dfs(string& a, string& b, int i, int j) {
        if (i == a.size() || j == b.size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (a[i] == b[j]) {
            dp[i][j] = dfs(a, b, i + 1, j + 1) + 1;
            return dp[i][j];
        }
        int aInc = dfs(a, b, i + 1, j);
        int bInc = dfs(a, b, i, j + 1);
        dp[i][j] = max(aInc, bInc);
        return dp[i][j];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        dp.assign(text1.size(), vector<int>(text2.size(), -1));
        return dfs(text1, text2, 0, 0);
    }
};
