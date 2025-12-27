class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int i, j, n, ans;
        n = points.size();
        ans = 0;
        for (i = 0; i < n; i++) {
            map<pair<double, double>, int> visitedPoint;
            for (j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                double x1 = points[i][0], y1 = points[i][1];
                double x2 = points[j][0], y2 = points[j][1];
                double slope = (y2 - y1) / (x2 - x1);
                double yCut = (x1 * y2 - x2 * y1) / (x1 - x2);
                visitedPoint[{slope, yCut}]++;
                ans = max(ans, visitedPoint[{slope, yCut}]);
                cout << slope << " " << yCut << endl;
            }
        }
        return ++ans;
    }
};