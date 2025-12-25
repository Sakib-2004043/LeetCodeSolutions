class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int suffix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = suffix;
            suffix *= nums[i];
        } // Ignores Last Element
        
        int prefix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= prefix;
            prefix *= nums[i];
        } // Ignores First Element

        return ans;
    }
};