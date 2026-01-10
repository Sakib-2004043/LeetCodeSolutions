class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row, col, steps, ans;
        queue<vector<int>> cells;
        row = maze.size();
        col = maze[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        cells.push(entrance);
        visited[entrance[0]][entrance[1]] = true;
        steps = 0, ans = -1;
        while (!cells.empty()) {
            int sz = cells.size();
            while (sz--) {
                int x = cells.front()[0];
                int y = cells.front()[1];
                if (cells.front() != entrance &&
                    (x == 0 || y == 0 || x == row - 1 || y == col - 1)) {
                    ans = steps;
                    goto last;
                }
                if (x > 0 && maze[x - 1][y] == '.' && !visited[x - 1][y]) {
                    cells.push({x - 1, y});
                    visited[x - 1][y] = true;
                }
                if (y > 0 && maze[x][y - 1] == '.' && !visited[x][y - 1]) {
                    cells.push({x, y - 1});
                    visited[x][y - 1] = true;
                }
                if (x + 1 < row && maze[x + 1][y] == '.' &&
                    !visited[x + 1][y]) {
                    cells.push({x + 1, y});
                    visited[x + 1][y] = true;
                }
                if (y + 1 < col && maze[x][y + 1] == '.' &&
                    !visited[x][y + 1]) {
                    cells.push({x, y + 1});
                    visited[x][y + 1] = true;
                }
                cells.pop();
            }
            steps++;
        }
    last:;
        return ans;
    }
};