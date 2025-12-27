class Solution {
public:
    double myFun(double num, long long power) {
        if (power == 1) {
            return num;
        }
        double half = myFun(num, power / 2);
        return power % 2 ? half * half * num : half * half;
    }
    double myPow(double x, long long n) {
        return n > 0 ? myFun(x, n) : myFun(1 / x, -n);
    }
};