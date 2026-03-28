class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
    stack<int> st;
    int n = h.size(), ans = 0;
    for (int i = 0; i <= n; i++) {
        int cur = (i == n ? 0 : h[i]);
        while (!st.empty() && h[st.top()] >= cur) {
            int height = h[st.top()];
            st.pop();
            int right = i;
            int left = st.empty() ? -1 : st.top();
            ans = max(ans, height * (right - left - 1));
        }
        st.push(i);
    }
    return ans;
}

};
