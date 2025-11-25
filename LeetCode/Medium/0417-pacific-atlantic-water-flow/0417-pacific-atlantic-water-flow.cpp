class Solution {
public:
    vector<vector<bool>> pacific;
    vector<vector<bool>> atlantic;
    vector<vector<bool>> visited;
    const vector<pair<int, int>> directions = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool check_atlantic(int cx, int cy, vector<vector<int>>& heights) {

        int row = heights.size();
        int col = heights[0].size();
        bool result = false;

        visited[cx][cy] = true;

        // if (atlantic[cx][cy]) {
        //     return true;
        // }

        if (cy + 1 == col || cx + 1 == row) {
            // atlantic[cx][cy] = true;
            return true;
        }

        for (auto [dx, dy] : directions) {
            int nx = cx + dx;
            int ny = cy + dy;

            bool valid = (nx >= 0 && ny >= 0 && nx < row && ny < col);
            if (valid && !visited[nx][ny] &&
                heights[nx][ny] <= heights[cx][cy]) {

                result = check_atlantic(nx, ny, heights);
                if(result){
                    return result;
                }
            }
        }
        return result;
    }
    bool check_pacific(int cx, int cy, vector<vector<int>>& heights) {

        int row = heights.size();
        int col = heights[0].size();
        bool result = false;

        visited[cx][cy] = true;

        // if (pacific[cx][cy]) {
        //     return true;
        // }

        if (cy == 0 || cx == 0) {
            // pacific[cx][cy] = true;
            return true;
        }

        for (auto [dx, dy] : directions) {
            int nx = cx + dx;
            int ny = cy + dy;

            bool valid = (nx >= 0 && ny >= 0 && nx < row && ny < col);
            if (valid && !visited[nx][ny] &&
                heights[nx][ny] <= heights[cx][cy]) {

                result = check_pacific(nx, ny, heights);
                if(result){
                    return result;
                }
            }
        }
        return result;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int i, j;
        vector<vector<int>> ans;

        int row = heights.size();
        int col = heights[0].size();

        pacific.assign(row, vector<bool>(col, false));
        atlantic.assign(row, vector<bool>(col, false));

        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                visited.assign(row, vector<bool>(col, false));
                bool isAtlantic = check_atlantic(i, j, heights);
                visited.assign(row, vector<bool>(col, false));
                bool isPacific = check_pacific(i, j, heights);

                if (isAtlantic && isPacific) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};