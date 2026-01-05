class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0, row = grid.size();
        for (int i = 0; i < row; i++) {
            int col = grid[i].size();
            int left = 0, right = col - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (grid[i][mid] >= 0) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            ans += (col - right - 1);
        }
        return ans;
    }
};