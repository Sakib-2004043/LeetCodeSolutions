class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> points;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            points[nums[i]] += nums[i];
        }
        vector<int> ans(1e4 + 5, 0);
        int mx = ans[1] = points[1];
        for (int i = 2; i <= 1e4; i++) {
            ans[i] = max(mx, ans[i - 2] + points[i]);
            mx = max(mx, ans[i]);
        }
        return mx;
    }
};