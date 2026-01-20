class Solution {
private:
    void check_dfs(auto& board, auto& visited, int row, int col) {
        if (visited[row][col]) {
            return;
        }
        visited[row][col] = true;
        int totalRow = board.size();
        int totalCol = board[0].size();
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto& dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            if (newRow >= 0 && newRow < totalRow && newCol >= 0 &&
                newCol < totalCol && !visited[newRow][newCol] &&
                board[newRow][newCol] == 'O') {
                check_dfs(board, visited, newRow, newCol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            int j = 0;
            while (j < col) {
                if (board[i][j] == 'O') {
                    check_dfs(board, visited, i, j);
                }
                j += (i == 0 || i == row - 1) ? 1 : (col - 1);
            }
        }
        for (int i = 1; i < row - 1; i++) {
            for (int j = 1; j < col - 1; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};