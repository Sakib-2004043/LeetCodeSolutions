// Catalan number Cₙ.
// ans = (2n)!/(n+1)/((n!)^2)
class Solution {
public:
    int numTrees(int n) {
        long double ans = 1.0 / (n + 1);
        for (int i = 1; i <= 2 * n; i++) {
            ans *= i;
            if (i <= n) {
                ans /= i * i;
            }
        }
        return round(ans);
    }
};