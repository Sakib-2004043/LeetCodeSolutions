class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // if (pattern == s && s.size() > 1) {
        //     return false;
        // }
        int i, j, n;
        unordered_map<string, char> s_c;
        unordered_map<char, string> c_s;
        n = s.size();
        i = 0, j = 0;
        while (i < n) {
            string temp = "";
            if (!isalpha(s[i])) {
                i++;
                continue;
            }
            while (i < n && isalpha(s[i])) {
                temp += s[i];
                i++;
            }
            // cout << temp << " " << pattern[j] << endl;
            if (s_c.count(temp) == 0) {
                s_c[temp] = pattern[j];
            } else if (s_c[temp] != pattern[j]) {
                return false;
            }
            if (c_s.count(pattern[j]) == 0) {
                c_s[pattern[j]] = temp;
            } else if (c_s[pattern[j]] != temp) {
                return false;
            }
            j++;
        }
        if(i==n && j==pattern.size()){
            return true;
        }
        // cout<<i<<" "<<j;
        return false;;
    }
};