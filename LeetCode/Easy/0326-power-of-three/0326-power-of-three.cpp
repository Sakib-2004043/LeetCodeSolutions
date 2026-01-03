class Solution {
public:
    bool isPowerOfThree(int n) {
        long double ans = log(n) / log(3);
        return ans == round(ans) && n;
    }
};