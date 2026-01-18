class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> preSum = triangle[0];
        vector<int> newSum;
        for (int i = 1; i < n; i++) {
            newSum.clear();
            for (int j = 0; j <= i; j++) {
                int best = INT_MAX;
                if (j < preSum.size()) {
                    best = preSum[j];
                }
                if (j > 0) {
                    best = min(best, preSum[j - 1]);
                }
                newSum.push_back(best + triangle[i][j]);
            }
            preSum.swap(newSum);
        }
        return *min_element(preSum.begin(), preSum.end());
    }
};
