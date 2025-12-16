class Solution {
public:
    int candy(vector<int>& ratings) {
        int i, n, ans, prev, downLen, peak;
        n = ratings.size();
        ans = 1, prev = 1;
        downLen = 0, peak = 0;
        for (i = 1; i < n; i++) {
            if (ratings[i - 1] < ratings[i]) {
                ans = ans + prev + 1;
                prev++;
                downLen = 0;
                peak = prev;
            } else if (ratings[i - 1] == ratings[i]) {
                ans += 1;
                prev = 1;
                downLen = 0;
                peak = prev;
            } else if (ratings[i - 1] > ratings[i]) {
                downLen++;
                ans += downLen;
                if (downLen >= peak) {
                    ans += 1;
                }
                prev = 1;
            }
            // cout << ans << endl;
        }
        return ans;
    }
};