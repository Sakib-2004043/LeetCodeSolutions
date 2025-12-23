class Solution {
public:
    bool isPalindrome(string s) {
        int bgn = 0, end = s.size() - 1;

        while (bgn < end) {
            // skip non-alphanumeric from left
            while (bgn < end && !isalnum((unsigned char)s[bgn]))
                bgn++;

            // skip non-alphanumeric from right
            while (bgn < end && !isalnum((unsigned char)s[end]))
                end--;

            if (tolower((unsigned char)s[bgn]) !=
                tolower((unsigned char)s[end])) {
                return false;
            }

            bgn++;
            end--;
        }
        return true;
    }
};
