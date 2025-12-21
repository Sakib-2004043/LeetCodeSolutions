class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i, j, row, col, k;
        vector<int> ans;
        row = matrix.size();
        col = matrix[0].size();
        i = 0, j = 0, k = 0;
        for (i = 0, j = 0; j < row * col; i++) {
            k = i;
            while (j < row * col && k < col - i) {
                ans.push_back(matrix[i][k]);
                k++;
                j++;
            }
            k = i + 1;
            while (j < row * col && k < row - i) {
                ans.push_back(matrix[k][col - i - 1]);
                k++;
                j++;
            }
            k = col - i - 2;
            while (j < row * col && k >= i) {
                ans.push_back(matrix[row - i - 1][k]);
                k--;
                j++;
            }
            k = row - i - 2;
            while (j < row * col && k > i) {
                ans.push_back(matrix[k][i]);
                k--;
                j++;
            }
        }
        return ans;
    }
};