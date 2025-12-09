class Solution {
public:
    bool binary_search(vector<int>& row, int target) {
        int bgn, mid, end;
        bgn = 0;
        end = row.size() - 1;

        while (bgn <= end) {
            mid = bgn + (end - bgn) / 2;
            if (row[mid] == target) {
                return true;
            }
            if (row[mid] < target) {
                bgn = mid + 1;
                mid = bgn + (end - bgn) / 2;
            } else {
                end = mid - 1;
                mid = bgn + (end - bgn) / 2;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i, n;
        bool ans = false;

        n = matrix.size();
        for (i = 0; i < n; i++) {
            ans |= binary_search(matrix[i], target);
        }
        return ans;
    }
};