class Solution {
public:
    int jump(vector<int>& nums) {
        int i, n, ans;
        n = nums.size();
        vector<int> minJump(n + 5, INT_MAX);
        minJump[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= nums[i] && i + j < n; j++) {
                minJump[i + j] = min(minJump[i + j], minJump[i] + 1);
            }
        }
        return minJump[n - 1];
    }
};