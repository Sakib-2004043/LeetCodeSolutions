class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }                             // powers must be positive
        double ans = log(n) / log(4); // log base 4
        return abs(ans - round(ans)) < 1e-10;
    }
};
