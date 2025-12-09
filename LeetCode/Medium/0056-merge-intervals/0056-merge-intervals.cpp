class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<bool> merged(n, false); // track merged intervals
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            if (merged[i]) continue;
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            bool changed = true;
            while (changed) {
                changed = false;
                for (int j = 0; j < n; j++) {
                    if (i == j || merged[j]) continue;
                    int s = intervals[j][0], e = intervals[j][1];
                    
                    // check if current interval overlaps with interval[j]
                    if (!(end < s || start > e)) {
                        start = min(start, s);
                        end = max(end, e);
                        merged[j] = true;
                        changed = true;
                    }
                }
            }
            
            ans.push_back({start, end});
            merged[i] = true;
        }

        return ans;
    }
};
