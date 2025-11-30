class Solution {
public:
    string longestPalindrome(string s) {
        int i, j, k, n, ans, counter;
        string retString;
        n = s.size();

        ans = 0;
        for (i = 0; i < n; i++) {
            counter = 1;
            string tempString = "";
            tempString += s[i];
            for (j = i + 1, k = i - 1; j < n && k >= 0; j++, k--) {
                if (s[j] == s[k]) {
                    counter += 2;
                    tempString = s[k] + tempString + s[j];
                } else {
                    goto ff1;
                }
            }
        ff1:;
            if (counter > ans) {
                ans = counter;
                retString = tempString;
            }
        }
        // cout << "Prev : " << ans << endl;

        for (i = 0; i < n; i++) {
            counter = 0;
            string tempString = "";
            for (j = i + 1, k = i; j < n && k >= 0; j++, k--) {

                if (s[j] == s[k]) {
                    counter += 2;
                    tempString = s[k] + tempString + s[j];
                } else {
                    goto ff2;
                }
            }
        ff2:;
            if (counter > ans) {
                ans = counter;
                retString = tempString;
            }
        }
        // cout << "Next : " << ans << endl;
        return retString;
    }
};