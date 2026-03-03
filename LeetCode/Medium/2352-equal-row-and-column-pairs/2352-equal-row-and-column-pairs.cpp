class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> rows;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            vector<int> row;
            for (int j = 0; j < n; j++) {
                row.push_back(grid[j][i]);
            }
            rows[row]++;
        }
        int ans = 0;
        for (auto row : grid) {
            ans += rows[row];
        }
        return ans;
    }
};