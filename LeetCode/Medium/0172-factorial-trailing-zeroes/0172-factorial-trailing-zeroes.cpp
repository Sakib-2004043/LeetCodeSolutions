class Solution {
public:
    int trailingZeroes(int n) {
        int32_t ans = 0;
        for (int32_t i = 5; i <= n; i *= 5) {
            ans += n / i;
        }
        return ans;
    }
};