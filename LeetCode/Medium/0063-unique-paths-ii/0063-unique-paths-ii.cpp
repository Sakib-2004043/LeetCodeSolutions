class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i, j, row, col;
        row = obstacleGrid.size();
        col = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[row - 1][col - 1] == 1) {
            return 0;
        }
        vector<vector<int>> dp(row, vector<int>(col, 0));
        dp[0][0] = 1;
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                if (obstacleGrid[i][j] != 1) {
                    if (i > 0) {
                        dp[i][j] += dp[i - 1][j];
                    }
                    if (j > 0) {
                        dp[i][j] += dp[i][j - 1];
                    }
                }
            }
        }
        return dp[row - 1][col - 1];
    }
};