class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row = maze.size();
        int col = maze[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int, int>> q;

        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                if (!(x == entrance[0] && y == entrance[1]) &&
                    (x == 0 || y == 0 || x == row - 1 || y == col - 1)) {
                    return steps;
                }

                if (x > 0 && maze[x - 1][y] == '.' && !visited[x - 1][y]) {
                    visited[x - 1][y] = true;
                    q.push({x - 1, y});
                }
                if (y > 0 && maze[x][y - 1] == '.' && !visited[x][y - 1]) {
                    visited[x][y - 1] = true;
                    q.push({x, y - 1});
                }
                if (x + 1 < row && maze[x + 1][y] == '.' &&
                    !visited[x + 1][y]) {
                    visited[x + 1][y] = true;
                    q.push({x + 1, y});
                }
                if (y + 1 < col && maze[x][y + 1] == '.' &&
                    !visited[x][y + 1]) {
                    visited[x][y + 1] = true;
                    q.push({x, y + 1});
                }
            }
            steps++;
        }
        return -1;
    }
};
