class Solution {
private:
    void dfs(auto& grid, auto& visited, int row, int col) {
        if (visited[row][col]) {
            return;
        }
        int totalRow = grid.size();
        int totalCol = grid[0].size();
        visited[row][col] = true;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            if (newRow >= 0 && newCol >= 0 && newRow < totalRow &&
                newCol < totalCol && !visited[newRow][newCol] &&
                grid[newRow][newCol] == 1) {
                grid[newRow][newCol] = 0;
                dfs(grid, visited, newRow, newCol);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i > 0 && j > 0 && i < row - 1 && j < col - 1) {
                    continue;
                }
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    dfs(grid, visited, i, j);
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                sum += grid[i][j];
            }
        }
        return sum;
    }
};