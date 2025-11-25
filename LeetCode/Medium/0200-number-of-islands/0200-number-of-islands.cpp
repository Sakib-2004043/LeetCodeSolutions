map<int, map<int, bool>> visited;
const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void dfs(int row, int col, vector<vector<char>>& grid) {
    int rmax = grid.size();
    int cmax = grid[0].size();
    visited[row][col] = true;
    for (auto [dx, dy] : directions) {
        int nx = row + dx;
        int ny = col + dy;
        bool valid = (nx >= 0 && ny >= 0 && nx < rmax && ny < cmax);
        if (valid && !visited[nx][ny] && grid[nx][ny] == '1') {
            dfs(nx, ny, grid);
        }
    }
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int i, j, r, c, components;
        visited.clear();
        r = grid.size();
        c = grid[0].size();
        components = 0;
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    components++;
                    dfs(i, j, grid);
                }
            }
        }

        return components;
    }
};