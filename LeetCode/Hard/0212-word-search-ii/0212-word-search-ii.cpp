class Solution {
private:
    vector<vector<bool>> visited;
    unordered_set<string> ans;
    unordered_set<string> wordSet;
    unordered_set<string> prefixSet;

    vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void backTrackDFS(vector<vector<char>>& board, int row, int col,
                      string& curWord) {
        if (prefixSet.count(curWord) == 0) {
            return;
        }
        if (wordSet.count(curWord)) {
            ans.insert(curWord);
        }
        visited[row][col] = true;
        for (auto& d : directions) {
            int nr = row + d[0], nc = col + d[1];
            if (nr >= 0 && nc >= 0 && nr < board.size() &&
                nc < board[0].size() && !visited[nr][nc]) {

                curWord.push_back(board[nr][nc]);
                backTrackDFS(board, nr, nc, curWord);
                curWord.pop_back();
            }
        }
        visited[row][col] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        int r = board.size(), c = board[0].size();
        for (string& w : words) {
            wordSet.insert(w);
            for (int i = 1; i <= w.size(); i++) {
                prefixSet.insert(w.substr(0, i));
            }
        }
        visited.assign(r, vector<bool>(c, false));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                string cur;
                cur.push_back(board[i][j]);
                backTrackDFS(board, i, j, cur);
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};
