class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size(), ans = 0;
        const int MOD = 1e9 + 7;
        vector<int> power(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            power[i] = (power[i - 1] * 2) % MOD;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int left = i, right = n - 1;
            int best = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[i] + nums[mid] <= target) {
                    best = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (best != -1) {
                ans = (ans + power[best - i]) % MOD;
            }
        }
        return ans;
    }
};
