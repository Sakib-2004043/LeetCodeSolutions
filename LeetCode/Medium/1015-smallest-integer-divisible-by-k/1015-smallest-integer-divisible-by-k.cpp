class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }
        int remainder = 0;
        for (int i = 1; i <= k; i++) {
            remainder = (remainder * 10 + 1) % k;
            cout << remainder << endl;
            if (remainder % k == 0) {
                return i;
            }
        }
        return 0;
    }
};