class Solution {
private:
    string targetWord;
    bool ans = false;
    vector<vector<bool>> visited;

public:
    void search(vector<vector<char>>& board, string curWord, int row, int col) {
        if (curWord == targetWord) {
            ans = true;
            return;
        }
        if (curWord.size() >= targetWord.size()) {
            return;
        }
        visited[row][col] = true;
        if (row + 1 < board.size() && !visited[row + 1][col]) {
            search(board, curWord + board[row + 1][col], row + 1, col);
        }
        if (row - 1 >= 0 && !visited[row - 1][col]) {
            search(board, curWord + board[row - 1][col], row - 1, col);
        }
        if (col + 1 < board[0].size() && !visited[row][col + 1]) {
            search(board, curWord + board[row][col + 1], row, col + 1);
        }
        if (col - 1 >= 0 && !visited[row][col - 1]) {
            search(board, curWord + board[row][col - 1], row, col - 1);
        }
        visited[row][col] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->targetWord = word;
        int row = board.size();
        int col = board[0].size();
        visited.assign(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                search(board, string(1, board[i][j]), i, j);
            }
        }
        return ans;
    }
};