class Solution {
private:
    static bool cmp2(const vector<int>& a, const vector<int>& b) {
        // if (a[1] == b[1]) {
        //     return a[0] < b[0];
        // }
        return a[1] < b[1];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp2);
        int remove = 0;
        int preEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < preEnd) {
                remove++;
            } else {
                preEnd = intervals[i][1];
            }
        }
        return remove;
    }
};