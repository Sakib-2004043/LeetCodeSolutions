class Solution {
private:
    string dfs(string& s, int& idx) {
        string ans = "";
        while (idx < s.size()) {
            if (s[idx] == '[') {
                idx++;
                continue;
            }
            if (s[idx] == ']') {
                idx++;
                return ans;
            }
            if (isalpha(s[idx])) {
                ans += s[idx++];
                continue;
            }
            int digit = 0;
            while (isdigit(s[idx])) {
                digit *= 10;
                digit += (s[idx] - '0');
                idx++;
            }
            string temp = dfs(s, idx);
            for (int j = 1; j <= digit; j++) {
                ans += temp;
            }
        }
        return ans;
    }

public:
    string decodeString(string s) {
        int i = 0;
        return dfs(s, i);
    }
};