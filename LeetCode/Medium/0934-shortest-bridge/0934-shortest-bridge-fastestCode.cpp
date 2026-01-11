class Solution {
public:
    void dfs(
        int row,
        int col,
        vector<vector<int>>& grid,
        vector<vector<bool>>& visited,
        queue<pair<int,int>>& q,
        int n
    ) {
        visited[row][col] = true;
        q.push({row, col});

        static int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        for (auto &d : dirs) {
            int newRow = row + d[0];
            int newCol = col + d[1];

            if (newRow >= 0 && newRow < n &&
                newCol >= 0 && newCol < n &&
                !visited[newRow][newCol] &&
                grid[newRow][newCol] == 1) {

                dfs(newRow, newCol, grid, visited, q, n);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int,int>> q;

        // Step 1: find first island
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid, visited, q, n);
                    found = true;
                }
            }
        }

        // Step 2: BFS expansion
        int steps = 0;
        static int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [row, col] = q.front();
                q.pop();

                for (auto &d : dirs) {
                    int newRow = row + d[0];
                    int newCol = col + d[1];

                    if (newRow >= 0 && newRow < n &&
                        newCol >= 0 && newCol < n &&
                        !visited[newRow][newCol]) {

                        if (grid[newRow][newCol] == 1)
                            return steps;

                        visited[newRow][newCol] = true;
                        q.push({newRow, newCol});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
