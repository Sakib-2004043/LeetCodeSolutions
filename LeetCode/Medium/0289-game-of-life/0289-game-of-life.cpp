class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> ones(row, vector<int>(col, 0));
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                                    {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                for (auto dir : dirs) {
                    int nr = i + dir[0];
                    int nc = j + dir[1];
                    if (nr < row && nc < col && nr >= 0 && nc >= 0 &&
                        board[nr][nc] == 1) {
                        ones[i][j]++;
                    }
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (ones[i][j] < 2) {
                    board[i][j] = 0;
                } else if (ones[i][j] == 3) {
                    board[i][j] = 1;
                } else if (ones[i][j] > 3) {
                    board[i][j] = 0;
                }
            }
        }
    }
};