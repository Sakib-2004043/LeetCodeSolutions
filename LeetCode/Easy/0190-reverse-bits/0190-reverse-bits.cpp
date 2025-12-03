class Solution {
public:
    int reverseBits(int n) {
        int i, ans, lastBit;

        ans = 0;
        for (i = 0; i < 32; i++) {
            lastBit = n & 1;
            ans <<= 1;
            ans |= lastBit;
            n >>= 1;
        }
        return ans;
    }
};