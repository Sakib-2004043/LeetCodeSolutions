class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i, j, row, col;
        set<int> rowSet, colSet;
        row = matrix.size();
        col = matrix[0].size();
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                if (!matrix[i][j]) {
                    rowSet.insert({i});
                    colSet.insert({j});
                }
            }
        }
        for (auto rw : rowSet) {
            for (j = 0; j < col; j++) {
                matrix[rw][j] = 0;
            }
        }
        for (auto cl : colSet) {
            for (i = 0; i < row; i++) {
                matrix[i][cl] = 0;
            }
        }
    }
};