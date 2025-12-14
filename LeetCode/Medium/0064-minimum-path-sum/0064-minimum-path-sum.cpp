class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int i, j, row, col;
        row = grid.size();
        col = grid[0].size();
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                if(!i&&!j){
                    continue;
                }
                int top = INT_MAX, left = INT_MAX;
                if (i != 0) {
                    top = grid[i - 1][j];
                }
                if (j != 0) {
                    left = grid[i][j - 1];
                }
                grid[i][j] = grid[i][j]+min(left, top);
            }
        }
        // for (auto row : grid) {
        //     for (auto cell : row) {
        //         cout << cell << " ";
        //     }
        //     cout << endl;
        // }
        return grid[row - 1][col - 1];
    }
};