class Solution {
public:
    string reverseWords(string s) {
        int i, j, n;
        string ans = "";
        n = s.size();
        for (i = 0, j = 0; i < n; i++) {
            string temp = "";
            while (i < n && !isspace(s[i])) {
                temp = temp + s[i];
                i++;
            }
            if(temp == ""){
                continue;
            }
            if (ans == "") {
                ans += temp;
            } else
                ans = temp + " " + ans;
        }
        return ans;
    }
};