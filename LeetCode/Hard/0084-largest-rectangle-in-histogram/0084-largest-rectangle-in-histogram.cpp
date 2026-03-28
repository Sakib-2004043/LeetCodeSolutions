class Solution {
private:
    vector<int> makeArr(auto& ht, int bgn, int end, int it) {
        stack<int> st;
        int n = ht.size();
        vector<int> sn(n, 0);
        for (int i = bgn; i != end; i += it) {
            while (!st.empty() && ht[st.top()] >= ht[i]) {
                st.pop();
            }
            sn[i] = !st.empty() ? st.top() : (it == 1 ? -1 : n);
            st.push(i);
        }
        return sn;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> lsn = makeArr(heights, 0, n, 1);
        vector<int> rsn = makeArr(heights, n - 1, -1, -1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int area = heights[i] * (rsn[i] - lsn[i] - 1);
            ans = max(ans, area);
        }
        return ans;
    }
};
