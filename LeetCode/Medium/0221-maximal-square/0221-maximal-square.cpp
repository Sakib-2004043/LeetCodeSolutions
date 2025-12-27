class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row, col, ans;
        row = matrix.size();
        col = matrix[0].size();
        vector<vector<int>> area(row, vector<int>(col, 0));
        ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 || j == 0) {
                    area[i][j] = matrix[i][j] - '0';
                    ans = max(ans, area[i][j]);
                    continue;
                }
                if (matrix[i][j] == '0') {
                    area[i][j] = 0;
                    continue;
                }
                int mn = min(area[i - 1][j], area[i][j - 1]);
                mn = min(mn, area[i - 1][j - 1]);
                area[i][j] = mn + 1;
                ans = max(ans, area[i][j]);
            }
        }
        return ans * ans;
    }
};