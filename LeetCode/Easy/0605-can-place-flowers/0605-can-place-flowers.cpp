class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int sz = fb.size(), count = 0;
        if (n == 0 || (sz == 1 && fb[0] == 0 && n == 1)) {
            return true;
        }
        if (sz > 1 && fb[0] == 0 && fb[1] == 0) {
            count++;
            fb[0] = 1;
        }
        if (sz > 1 && fb[sz - 1] == 0 && fb[sz - 2] == 0) {
            count++;
            fb[sz - 1] = 1;
        }
        for (int i = 1; i < sz - 1; i++) {
            if (fb[i] == 0 && fb[i - 1] == 0 && fb[i + 1] == 0) {
                count++;
                fb[i] = 1;
            }
        }
        return count >= n;
    }
};