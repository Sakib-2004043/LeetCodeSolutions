class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> preSum = triangle[0]; 

        for (int i = 1; i < n; i++) {
            vector<int> newSum(i + 1, INT_MAX);

            for (int j = 0; j <= i; j++) {
                if (j > 0)
                    newSum[j] = min(newSum[j], preSum[j - 1] + triangle[i][j]);

                if (j < preSum.size())
                    newSum[j] = min(newSum[j], preSum[j] + triangle[i][j]);
            }

            preSum = newSum;
        }

        return *min_element(preSum.begin(), preSum.end());
    }
};
