class Solution {
private:
    set<vector<string>> ans;
    vector<string> words;
    unordered_map<string, bool> visited;
    void makeSquare(vector<string>& square, int idx) {
        // cout << square.size() << " ";
        if (square.size() == 2) {
            if (square[0][0] != square[1][0]) {
                return;
            }
        } else if (square.size() == 3) {
            if (square[0][3] != square[2][0]) {
                return;
            }
        } else if (square.size() == 4) {
            if (square[3][0] == square[1][3] && square[3][3] == square[2][3]) {
                ans.insert(square);
            }
            return;
        }
        for (int i = 0; i < words.size(); i++) {
            if (visited[words[i]] == false) {
                square.push_back(words[i]);
                visited[words[i]] = true;
                // swap(words[i],words[idx]);
                makeSquare(square, i + 1);
                // swap(words[i],words[idx]);
                square.pop_back();
                visited[words[i]] = false;
            }  
        }
    }

public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        this->words = words;
        vector<string> square;
        makeSquare(square, 0);
        vector<vector<string>> result;
        for (auto v : ans) {
            result.push_back(v);
        }
        return result;
    }
};