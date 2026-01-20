class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> v(n, 0);
        int ans = 0;
        for (int i = 0; i < roads.size(); i++) {
            v[roads[i][0]]++;
            v[roads[i][1]]++;
            if (roads[i][0] > roads[i][1]) {
                swap(roads[i][0], roads[i][1]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = v[i] + v[j];
                vector<int> edge = {i, j};
                if (find(roads.begin(), roads.end(), edge) != roads.end()) {
                    sum--;
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};