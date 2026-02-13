class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> visited(200);
        int n = s.size();
        if (n == 1) {
            return 1;
        }
        int mx = 0, i = 0, j = 0;
        while (i < n) {
            if (!visited[s[i]]) {
                visited[s[i]] = true;
                i++;
            } else {
                mx = max(mx, i - j);
                visited[s[j]] = false;
                j++;
            }
        }
        mx = max(mx, i - j);
        return mx;
    }
};