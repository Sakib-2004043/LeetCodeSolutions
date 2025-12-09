class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j, k, l;
        unordered_map<char, bool> visited;

        for (i = 0; i < 9; i++) {
            visited.clear();
            for (j = 0; j < 9; j++) {
                if (visited[board[i][j]]) {
                    return false;
                }
                if (board[i][j] != '.') {
                    visited[board[i][j]] = true;
                }
            }
        }
        for (i = 0; i < 9; i++) {
            visited.clear();
            for (j = 0; j < 9; j++) {
                if (visited[board[j][i]]) {
                    return false;
                }
                if (board[j][i] != '.') {
                    visited[board[j][i]] = true;
                }
            }
        }

        for (i=0;i<9;i+=3){
            for(j=0;j<9;j+=3){
                visited.clear();
                for(k=i;k<i+3;k++){
                    for(l=j;l<j+3;l++){
                        if (visited[board[k][l]]) {
                            return false;
                        }
                        if (board[k][l] != '.') {
                            visited[board[k][l]] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};