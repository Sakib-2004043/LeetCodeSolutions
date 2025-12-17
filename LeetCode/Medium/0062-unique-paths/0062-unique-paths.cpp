class Solution {
public:
    int uniquePaths(int m, int n) {
        int i, j;
        vector<vector<int>> grid(m, vector<int>(n, 1));
        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                grid[i][j] = 0;
                grid[i][j] += (grid[i - 1][j] + grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};