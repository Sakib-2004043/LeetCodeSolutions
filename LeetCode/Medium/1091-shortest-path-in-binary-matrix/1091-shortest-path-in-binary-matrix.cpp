class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) {
            return -1;
        }
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                                          {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        queue<pair<int, int>> bfsQ;
        bfsQ.push({0, 0});
        visited[0][0] = true;
        int steps = 1;
        while (!bfsQ.empty()) {
            int sz = bfsQ.size();
            while (sz--) {
                auto [x, y] = bfsQ.front();
                bfsQ.pop();
                if (x + 1 == n && y + 1 == n && grid[x][y] == 0) {
                    return steps;
                }
                for (auto& dir : directions) {
                    int nr = x + dir[0];
                    int nc = y + dir[1];
                    if (nc >= 0 && nr >= 0 && nc < n && nr < n &&
                        grid[nr][nc] == 0 && !visited[nr][nc]) {
                        bfsQ.push({nr, nc});
                        visited[nr][nc] = true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};