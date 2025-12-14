class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int i, j, n, m, k, ans;
        vector<int> preSum;
        n = triangle.size();
        if (n == 1) {
            return triangle[0][0];
        }
        preSum = triangle[0];
        ans = 0;
        for (i = 1; i < n; i++) {
            vector<int> newSum;
            m = preSum.size();
            k = n%2;
            for (j = 0; j < m; j++) {
                newSum.push_back(preSum[j] + triangle[i][j]);
                if (k) {
                    newSum.push_back(preSum[j] + triangle[i][j + 1]);
                    k = 0;
                } else {
                    k = 1;
                    newSum.back() =
                        min(newSum.back(), preSum[j] + triangle[i][j + 1]);
                }
            }
            ans = *min_element(newSum.begin(),newSum.end());
            for (auto x : newSum) {
                cout << x << " ";
            }
            cout << endl;
            preSum = newSum;
        }
        return ans;
    }
};