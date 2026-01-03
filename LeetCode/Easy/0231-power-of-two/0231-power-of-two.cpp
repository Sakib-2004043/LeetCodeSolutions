class Solution {
public:
    bool isPowerOfTwo(int n) {
        long double ans = log2(n);
        return ans == round(ans) && n;
    }
};