class Solution {
public:
    int squareSum(int n) {
        int sum = 0;
        while (n) {
            sum = sum + (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int k = 0;
        while (true) {
            if (n == 1) {
                return true;
            }
            // cout << n << endl;
            n = squareSum(n);
            k++;
            if (k == 100) {
                break;
            }
        }
        return false;
    }
};