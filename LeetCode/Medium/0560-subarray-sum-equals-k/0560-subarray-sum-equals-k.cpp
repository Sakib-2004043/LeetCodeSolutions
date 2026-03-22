class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0, preSum = 0;
        int n = nums.size();
        unordered_map<int, int> sumCount;
        sumCount[0] = 1;
        for (int i = 0; i < n; i++) {
            preSum += nums[i] ;
            cnt += sumCount[preSum - k];
            sumCount[preSum] += 1;
        }
        return cnt;
    }
};