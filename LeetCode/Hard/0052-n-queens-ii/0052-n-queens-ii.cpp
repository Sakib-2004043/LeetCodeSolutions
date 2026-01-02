class Solution {
private:
    vector<vector<string>> ans;
    bool isSafe(vector<string>& board, int row, int col) {
        int n = board.size();
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
    void makePosition(vector<string>& board, int row) {
        int n = board.size();
        if(row == n){
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';
                makePosition(board, row + 1);
            }
            board[row][col] = '.';
        }
    }

public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        makePosition(board, 0);
        return ans.size();
    }
};