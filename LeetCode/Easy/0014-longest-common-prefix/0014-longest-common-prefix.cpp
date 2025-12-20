class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i, n, j;
        string ans = "";
        n = strs.size();
        for (i = 0; i < n; i++) {
            if (strs[i] == "")
                break;
            char c = strs[0][i];
            bool present = true;
            for (j = 1; j < n; j++) {
                if (strs[j][i] != c) {
                    present = false;
                    break;
                }
            }
            if (present) {
                ans += c;
            } else
                break;
        }
        return ans;
    }
};