class Solution {
private:
    queue<pair<int, int>> cellQ;
    vector<vector<bool>> visited;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void make_1_dfs(auto& mat, auto& ans, int row, int col) {
        if (visited[row][col]) {
            return;
        }
        visited[row][col] = true;
        for (auto& dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            if (newRow >= 0 && newCol >= 0 && newRow < mat.size() &&
                newCol < mat[0].size() && !visited[newRow][newCol]) {
                if (mat[newRow][newCol] == 1) {
                    ans[newRow][newCol] = 1;
                    cellQ.push({newRow, newCol});
                } else {
                    ans[newRow][newCol] = 0;
                    make_1_dfs(mat, ans, newRow, newCol);
                }
            }
        }
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> ans(row, vector<int>(col, -1));
        visited.assign(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    make_1_dfs(mat, ans, i, j);
                }
            }
        }
        int val = 2;
        while (!cellQ.empty()) {
            int sz = cellQ.size();
            while (sz--) {
                auto [x, y] = cellQ.front();
                cellQ.pop();
                for (auto dir : directions) {
                    int newRow = x + dir[0];
                    int newCol = y + dir[1];
                    if (newRow >= 0 && newCol >= 0 && newRow < row &&
                        newCol < col && !visited[newRow][newCol] &&
                        ans[newRow][newCol] == -1) {
                        ans[newRow][newCol] = val;
                        cellQ.push({newRow, newCol});
                        visited[newRow][newCol] = true;
                    }
                }
            }
            val++;
        }
        return ans;
    }
};
