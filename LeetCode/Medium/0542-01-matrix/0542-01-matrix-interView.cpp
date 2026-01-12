class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, -1));
        queue<pair<int, int>> q;
        // Push all 0 cells into queue
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        // Multi-source BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr >= 0 && nc >= 0 && nr < rows && nc < cols &&
                    ans[nr][nc] == -1) {
                    ans[nr][nc] = ans[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return ans;
    }
};
