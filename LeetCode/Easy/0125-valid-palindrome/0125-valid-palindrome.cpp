class Solution {
public:
    bool isPalindrome(string s) {
        int i, bgn, end;
        i = 0;
        while (i < s.size()) {
            if (!isalnum(s[i])) {
                s.erase(i, 1);
            } else {
                s[i] = tolower(s[i]);
                i++;
            }
        }
        cout<<s;
        bgn = 0;
        end = s.size() - 1;
        while (bgn <= end) {
            if (s[bgn] != s[end]) {
                return false;
            }
            bgn++;
            end--;
        }
        return true;
    }
};