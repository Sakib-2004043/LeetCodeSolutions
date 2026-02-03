class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        int start = 0;    // starting index of longest palindrome
        int maxLen = 1;   // length of longest palindrome

        for (int i = 0; i < n; i++) {

            // --------- ODD length palindromes ----------
            int left = i;
            int right = i + (n+1)%2;

            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > maxLen) {
                    start = left;
                    maxLen = len;
                }
                left--;
                right++;
            }

            // // --------- EVEN length palindromes ----------
            // left = i;
            // right = i + 1;

            // while (left >= 0 && right < n && s[left] == s[right]) {
            //     int len = right - left + 1;
            //     if (len > maxLen) {
            //         start = left;
            //         maxLen = len;
            //     }
            //     left--;
            //     right++;
            // }
        }

        return s.substr(start, maxLen);
    }
};
