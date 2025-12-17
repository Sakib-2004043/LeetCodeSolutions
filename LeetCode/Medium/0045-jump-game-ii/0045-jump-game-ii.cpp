class Solution {
public:
    int jump(vector<int>& nums) {
        int i, n, end, farthest, jump;
        n = nums.size();
        jump = 0, end = 0;
        farthest = 0;
        for (i = 0; i < n-1; i++) {
            farthest = max(farthest, nums[i] + i);
            if (i == end) {
                // cout<<i<<endl;
                jump++;
                end = farthest;
            }
        }
        return jump;
    }
};