class Solution {
private:
    int rows, cols;

    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int k) {

        // all characters matched
        if (k == word.size())
            return true;

        // out of bounds or mismatch
        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != word[k])
            return false;

        char temp = board[r][c];
        board[r][c] = '#'; // mark visited

        bool found = dfs(board, word, r + 1, c, k + 1) ||
                     dfs(board, word, r - 1, c, k + 1) ||
                     dfs(board, word, r, c + 1, k + 1) ||
                     dfs(board, word, r, c - 1, k + 1);

        board[r][c] = temp; // backtrack
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
