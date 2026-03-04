class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> q;
        int z = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                z |= grid[i][j];
            }
        }
        if (q.empty()) {
            return z ? -1 : 0;
        }
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int ans = -1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : dirs) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < row && ny >= 0 && ny < col &&
                        grid[nx][ny] == 1) {
                        q.push({nx, ny});
                        grid[nx][ny] = 2;
                    }
                }
            }
            ans++;
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
};