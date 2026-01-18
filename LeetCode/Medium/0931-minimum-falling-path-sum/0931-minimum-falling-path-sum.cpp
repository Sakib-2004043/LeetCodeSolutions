class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rowCol = matrix.size();
        for (int i = 1; i < rowCol; i++) {
            for (int j = 0; j < rowCol; j++) {
                int topLeft = INT_MAX;
                int topRight = INT_MAX;
                int mn = INT_MAX;
                if (j > 0) {
                    topLeft = matrix[i - 1][j - 1];
                    mn = min(mn, topLeft);
                }
                if (j < rowCol - 1) {
                    topRight = matrix[i - 1][j + 1];
                    mn = min(mn, topRight);
                }
                mn = min(mn, matrix[i - 1][j]);
                matrix[i][j] += mn;
            }
        }
        return *min_element(matrix[rowCol - 1].begin(),
                            matrix[rowCol - 1].end());
    }
};