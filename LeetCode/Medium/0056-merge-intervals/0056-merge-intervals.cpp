class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i, n;
        vector<vector<int>> ans;
        n = intervals.size();
        // sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for (i = 1; i < n; i++) {
            vector<int> newPair = intervals[i];
            vector<int> ansPair = ans.back();
            if (ansPair[1] >= newPair[1] && ansPair[0] <= newPair[0]) {
                continue;
            }
            if (ansPair[0] > newPair[0]) {
                swap(ansPair, newPair);
            }

            if (ansPair[1] >= newPair[0]) {
                ans.pop_back();
                ans.push_back(
                    {min(ansPair[0], newPair[0]), max(ansPair[1], newPair[1])});
            } else if (ansPair[1] < newPair[0]) {
                ans.push_back(newPair);
            }
        }

        return ans;
    }
};