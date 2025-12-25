class Solution {
public:
    bool isValid(string s) {
        int i, n;
        stack<char> bracket;
        n = s.size();
        for (i = 0; i < n; i++) {
            bool empty = bracket.empty();
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                bracket.push(s[i]);
            } else if (bracket.empty() &&
                       (s[i] == ')' || s[i] == '}' || s[i] == ']')) {
                return false;
            } else if (bracket.top() == '{' && s[i] == '}') {
                bracket.pop();
            } else if (bracket.top() == '[' && s[i] == ']') {
                bracket.pop();
            } else if (bracket.top() == '(' && s[i] == ')') {
                bracket.pop();
            } else {
                return false;
            }
        }
        return bracket.empty() ? true : false;
    }
};