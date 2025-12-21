class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int i, j, n, ans;
        n = nums.size();
        ans = 0;
        for (i = 0; i < n; i++) {
            for (j = i; j < n; j++) {
                int diff = nums[i] ^ nums[j];
                while (diff) {
                    if (diff & 1)
                        ans++;
                    diff >>= 1;
                }
            }
        }
        return ans;
    }
};