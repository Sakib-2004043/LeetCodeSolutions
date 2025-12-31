class Solution {
public:
    int calculate(string s) {
        int i, n, k, ans;
        stack<string> st;
        s = '(' + s + ')';
        ans = 0;
        for (i = 0; i < s.size(); i++) {
            string digits = "";
            while (i < s.size() && isdigit(s[i])) {
                digits = digits + s[i];
                i++;
            }
            if (digits != "") {
                st.push(digits);
            }
            if (isspace(s[i])) {
                continue;
            }
            if (s[i] != ')') {
                st.push(string(1, s[i]));
                continue;
            }
            long long int num = 0;
            long long k = 1, tempAns = 0;
            while (st.top() != "(") {
                if (st.top() == "+") {
                    tempAns = tempAns + num;
                    num = 0, k = 0;
                } else if (st.top() == "-") {
                    tempAns = tempAns - num;
                    num = 0, k = 0;
                } else {
                    num = stoll(st.top());
                    k = 1;
                }
                st.pop();
                if (k && st.top() == "(") {
                    st.push("+");
                }
            }
            st.pop();
            st.push(to_string(tempAns));
            ans = tempAns;
        }
        return ans;
    }
};