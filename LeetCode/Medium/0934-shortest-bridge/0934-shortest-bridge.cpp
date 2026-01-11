class Solution {
private:
    queue<pair<int, int>> bfsQ;
    vector<vector<int>> visited;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(auto& grid, int row, int col) {
        visited[row][col] = true;
        bfsQ.push({row, col});
        int n = grid.size();
        for (auto dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                !visited[newRow][newCol] && grid[newRow][newCol] == 1) {
                dfs(grid, newRow, newCol);
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        visited.assign(n, vector<int>(n, false));
        int found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j]) {
                    dfs(grid, i, j);
                    found = true;
                }
            }
        }
        int steps = 0;
        while (!bfsQ.empty()) {
            int sz = bfsQ.size();
            while (sz--) {
                auto [row, col] = bfsQ.front();
                bfsQ.pop();
                for (auto dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];
                    if (newRow >= 0 && newRow < n && newCol >= 0 &&
                        newCol < n && !visited[newRow][newCol]) {
                        if (grid[newRow][newCol] == 1) {
                            return steps;
                        } else {
                            bfsQ.push({newRow, newCol});
                            visited[newRow][newCol] = true;
                        }
                    }
                }
            }
            steps++;
        }
        return steps;
    }
};