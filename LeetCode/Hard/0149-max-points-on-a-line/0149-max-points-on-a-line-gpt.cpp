class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2)
            return n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<string, int> slopeCount;
            int curMax = 0;
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                int g = __gcd(dy, dx);
                if (g != 0) {
                    dy /= g;
                    dx /= g;
                }
                string key = to_string(dy) + "/" + to_string(dx);
                slopeCount[key]++;
                curMax = max(curMax, slopeCount[key]);
            }
            ans = max(ans, curMax + 1); // +1 for the point itself
        }
        return ans;
    }
};
