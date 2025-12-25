class Solution {
public:
    int hIndex(vector<int>& citations) {
        int i, n, ans;
        n = citations.size();
        sort(citations.rbegin(), citations.rend());
        ans = 0;
        for (i = 0; i < n; i++) {
            if (citations[i] > ans) {
                ans++;
            }
        }
        return ans;
    }
};