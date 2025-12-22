class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long long n=0;
        int m = x;
        while (m) {
            n = n * 10 + (m % 10);
            m /= 10;
        }
        // cout<<n;
        return x == n;
    }
};