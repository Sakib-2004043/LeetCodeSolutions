class Solution {
public:
    const vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(int x, int y, vector<vector<int>>& heights,
             vector<vector<bool>>& reachable) {
        int m = heights.size();
        int n = heights[0].size();
        reachable[x][y] = true;

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && !reachable[nx][ny] &&
                heights[nx][ny] >= heights[x][y]) {
                dfs(nx, ny, heights, reachable);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(i, 0, heights, pacific);      // Left border (Pacific)
            dfs(i, n - 1, heights, atlantic); // Right border (Atlantic)
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j, heights, pacific);      // Top border (Pacific)
            dfs(m - 1, j, heights, atlantic); // Bottom border (Atlantic)
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};
