class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int maxLen = 0;

        // Left → Right pass
        int leftCount = 0, rightCount = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') leftCount++;
            else rightCount++;

            if (leftCount == rightCount) {
                // Update max length when balanced
                maxLen = max(maxLen, 2 * rightCount);
            } else if (rightCount > leftCount) {
                // Reset counters when invalid
                leftCount = rightCount = 0;
            }
        }

        // Right → Left pass (to catch unmatched '(' at the end)
        leftCount = rightCount = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') leftCount++;
            else rightCount++;

            if (leftCount == rightCount) {
                maxLen = max(maxLen, 2 * leftCount);
            } else if (leftCount > rightCount) {
                leftCount = rightCount = 0;
            }
        }

        return maxLen;
    }
};
