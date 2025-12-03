class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans, i;
        ans = 0;
        for (i = 31; i >= 0; i--) {
            int leftBit = (left >> i) & 1;
            int rightBit = (right >> i) & 1;

            if (rightBit && !leftBit) {
                goto lst;
            }

            if (leftBit && rightBit) {
                ans |= (1 << i);
            }
        }
    lst:;
        return ans;
    }
};