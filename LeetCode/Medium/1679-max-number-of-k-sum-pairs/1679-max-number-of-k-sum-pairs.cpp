auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
#pragma GCC optimize("O3") 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int ans = 0;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == k) {
                ans++;
                left++, right--;
            } else if (sum > k) {
                right--;
            } else {
                left++;
            }
        }
        return ans;
    }
};