class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i, n, ans;
        ans = 0;
        for (i = 0; i < 32; i++) {
            int sum = 0;
            for (auto x : nums) {
                sum += ((x >> i) & 1);
            }
            ans = ans | ((sum % 3) << i);
        }
        return ans;
    }
};