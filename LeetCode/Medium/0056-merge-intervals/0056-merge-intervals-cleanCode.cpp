class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& last = ans.back();
            vector<int>& current = intervals[i];

            if (last[1] >= current[0]) {
                // merge intervals directly
                last[1] = max(last[1], current[1]);
            } else {
                ans.push_back(current);
            }
        }

        return ans;
    }
};
