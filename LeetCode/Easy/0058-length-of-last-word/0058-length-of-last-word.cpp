class Solution {
public:
    int lengthOfLastWord(string s) {
        int i, n, j, ans;
        n = s.size();
        ans = 0;
        for (i = n - 1; i >= 0; i--) {
            if (isspace(s[i]) && !ans)
                continue;
            if (!isspace(s[i]))
                ans++;
            else
                break;
        }
        return ans;
    }
};