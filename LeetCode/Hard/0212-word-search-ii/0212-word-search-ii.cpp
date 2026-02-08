class Solution {
private:
    void backTrackDFS(vector<vector<char>>& board, int row, int col,
                      unordered_set<string>& ans,
                      unordered_set<string>& wordSet,
                      unordered_set<string>& prefixSet,
                      vector<vector<bool>>& visited,
                      vector<vector<int>>& directions, string& curWord) {

        if (prefixSet.count(curWord) == 0)
            return;

        if (wordSet.count(curWord)) {
            ans.insert(curWord);
        }

        visited[row][col] = true;

        int totalRow = board.size();
        int totalCol = board[0].size();

        for (auto& dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (newRow >= 0 && newCol >= 0 && newRow < totalRow &&
                newCol < totalCol && !visited[newRow][newCol]) {

                curWord.push_back(board[newRow][newCol]);
                backTrackDFS(board, newRow, newCol, ans, wordSet, prefixSet,
                             visited, directions, curWord);
                curWord.pop_back(); // 🔥 critical
            }
        }

        visited[row][col] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        int row = board.size();
        int col = board[0].size();

        unordered_set<string> ans, wordSet, prefixSet;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (string& w : words) {
            wordSet.insert(w);
            for (int i = 1; i <= w.size(); i++) {
                prefixSet.insert(w.substr(0, i));
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                string curWord;
                curWord.push_back(board[i][j]);

                backTrackDFS(board, i, j, ans, wordSet, prefixSet, visited,
                             directions, curWord);
            }
        }

        return vector<string>(ans.begin(), ans.end());
    }
};
