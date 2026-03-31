class Solution {
private:
    vector<vector<string>> ans;
    bool isSafe(auto& board, int row, int col) {
        int n = board[0].size();
        for (int i = 0; i < n; i++) {
            if (board[row][i] == 'Q' || board[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void addQueen(auto& board, int row) {
        int n = board[0].size();
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';
                addQueen(board, row + 1);
            }
            board[row][col] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        addQueen(board, 0);
        return ans;
    }
};