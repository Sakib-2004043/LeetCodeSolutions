class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> stk;
        stk.push(-1); // Base index for valid substring calculations

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i); // Store index of '('
            } else {
                stk.pop(); // Match with previous '('
                if (stk.empty()) {
                    stk.push(i); // Reset base index
                } else {
                    maxLen = max(maxLen, i - stk.top());
                }
            }
        }

        return maxLen;
    }
};
