class Solution {
private:
    unordered_set<string> ans;
    unordered_set<string> wordSet;
    vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    struct Trie {
        bool isEnd = false;
        Trie* child[26] = {nullptr};
    };
    void insertWord(Trie* root, string& word) {
        Trie* curNode = root;
        for (auto& w : word) {
            if (curNode->child[w - 'a'] == nullptr) {
                Trie* newNode = new Trie();
                curNode->child[w - 'a'] = newNode;
            }
            curNode = curNode->child[w - 'a'];
        }
        curNode->isEnd = true;
    }
    void backTrackDFS(vector<vector<char>>& board, int row, int col, Trie* node,
                      string& curWord) {
        char c = board[row][col];
        Trie* nextNode = node->child[c - 'a'];
        if (nextNode == nullptr) {
            return;
        }
        curWord.push_back(c);
        if (nextNode->isEnd) {
            ans.insert(curWord);
            node->isEnd = false;
        }
        board[row][col] = '#';
        for (auto& d : directions) {
            int nr = row + d[0];
            int nc = col + d[1];
            if (nr >= 0 && nc >= 0 && nr < board.size() &&
                nc < board[0].size() && board[nr][nc] != '#') {
                backTrackDFS(board, nr, nc, nextNode, curWord);
            }
        }
        curWord.pop_back();
        board[row][col] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        int r = board.size();
        int c = board[0].size();

        Trie* root = new Trie();
        for (auto word : words) {
            insertWord(root, word);
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                string cur = "";
                backTrackDFS(board, i, j, root, cur);
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};
