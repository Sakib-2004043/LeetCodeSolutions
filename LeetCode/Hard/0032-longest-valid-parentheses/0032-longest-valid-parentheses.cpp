class Solution {
public:
    int longestValidParentheses(string s) {
        int i, n, left, right, len, ptr;
        n = s.size();
        left = 0, right = 0;
        ptr = -1, len = 0;
        for (i = 0; i < n; i++) {
            if (s[i] == '(')
                left++;
            else
                right++;
            if(right>left){
                right=0;
                left=0;
                ptr = i;
            }
            else if(left==right){
                len = max(len,i-ptr);
            }
        }
        left = 0, right = 0;
        ptr = n;
        for (i = n-1; i >=0; i--) {
            if (s[i] == '(')
                left++;
            else
                right++;
            if(right<left){
                right=0;
                left=0;
                ptr = i;
            }
            else if(left==right){
                len = max(len,ptr-i);
            }
        }
        return len;
    }
};