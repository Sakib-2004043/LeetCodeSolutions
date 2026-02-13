class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, j, n, mx;
        unordered_map<char, bool> visited;
        n = s.size();
        if(n==1){
            return 1;
        }
        mx = 0;
        i = 0;
        j = 0;
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