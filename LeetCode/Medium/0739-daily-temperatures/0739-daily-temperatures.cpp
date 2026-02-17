class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> idx;
        int n = temp.size();
        vector<int> ans(n);
        ans[n - 1] = 0;
        idx.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            if (temp[i] < temp[i + 1]) {
                ans[i] = 1;
                idx.push(i);
                continue;
            }
            while (!idx.empty() && temp[i] >= temp[idx.top()]) {
                idx.pop();
            }
            if (idx.empty()) {
                ans[i] = 0;
                idx.push(i);
            } else {
                ans[i] = idx.top() - i;
                idx.push(i);
            }
        }
        return ans;
    }
};