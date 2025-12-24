class Solution {
public:
    int n, m;
    vector<vector<bool>> visited;

    const vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(int x, int y, vector<vector<char>>& grid) {
        visited[x][y] = true;
        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] &&
                grid[nx][ny] == '1') {
                dfs(nx, ny, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        visited.assign(n, vector<bool>(m, false));

        int components = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    components++;
                    dfs(i, j, grid);
                }
            }
        }

        return components;
    }
};
