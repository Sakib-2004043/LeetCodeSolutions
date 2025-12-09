class Solution {
public:
    string simplifyPath(string path) {
        int i, j, n;
        stack<string> st;
        string ret = "";
        n = path.size();
        for (i = 0; i < n; i++) {
            string temp = "";
            while (i < n && path[i] != '/') {
                temp += path[i];
                i++;
            }
            if (temp == ".") {
                continue;
            } else if (temp == ".." && !st.empty()) {
                st.pop();
            } else if (temp != "" && temp != "..") {
                st.push(temp);
            }
        }
        while (!st.empty()) {
            cout << "/" << st.top();
            ret = "/" + st.top() + ret;
            st.pop();
        }
        if (ret == "") {
            ret = "/";
        }
        return ret;
    }
};