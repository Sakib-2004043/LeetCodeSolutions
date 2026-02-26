class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int ax = a >> i & 1;
            int bx = b >> i & 1;
            int cx = c >> i & 1;
            if ((ax | bx) != cx) {
                ans += (ax & bx) ? 2 : 1;
            }
        }
        return ans;
    }
};