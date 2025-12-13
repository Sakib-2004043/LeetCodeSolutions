class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int i, n;
        n = nums.size();
        vector<int> money(n);
        money[0] = nums[0];
        money[1] = max(nums[0], nums[1]);

        for (i = 2; i < n; i++) {
            money[i] = max(money[i - 1], nums[i] + money[i - 2]);
        }
        return money[n - 1];
    }
};