class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, 1e5));
        for (auto e : edges) {
            matrix[e[0]][e[1]] = e[2];
            matrix[e[1]][e[0]] = e[2];
        }
        for (int i = 0; i < n; i++) {
            matrix[i][i] = 0;
        }
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int sum = matrix[i][via] + matrix[via][j];
                    matrix[i][j] = min(matrix[i][j], sum);
                }
            }
        }
        int ans = 0, mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            int city = 0;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] <= distanceThreshold) {
                    city++;
                }
            }
            if (city <= mn) {
                mn = city;
                ans = i;
            }
        }
        return ans;
    }
};