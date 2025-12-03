class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i, n, ans;
        map<int, int> visited;
        n = nums.size();
        for (i = 0; i < n; i++) {
            visited[nums[i]]++;
        }
        for (auto x : visited) {
            if (x.second == 1) {
                ans = x.first;
            }
        }
        return ans;
    }
};