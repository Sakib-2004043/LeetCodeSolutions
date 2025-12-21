class Solution {
public:
    int findComplement(int num) {
        int i, ans, flag;
        ans = 0, flag = 0;
        for (i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (bit) {
                flag = 1;
            }
            if (flag) {
                ans = ans | ((!bit) << i);
            }
        }
        return ans;
    }
};