class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int i, j, k, l, row, col, ans;
        row = matrix.size();
        col = matrix[0].size();
        vector<vector<int>> area(row, vector<int>(col, 0));
        ans = 0;
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                if (i == 0 || j == 0) {
                    area[i][j] = matrix[i][j] - '0';
                    ans = max(ans, area[i][j]);
                    continue;
                }
                if( matrix[i][j] == '0'){
                    area[i][j] = 0;
                    continue;
                }
                int mn = min(area[i - 1][j], area[i][j - 1]);
                mn = min(mn, area[i - 1][j - 1]);
                area[i][j] = mn + 1;
                ans = max(ans, area[i][j]);
                // cout<<i<<" "<<j<<" "<<ans<<endl;
            }
        }
        for (auto v : area) {
            for (auto x : v) {
                cout << x << " ";
            }
            cout << endl;
        }
        return ans * ans;
    }
};