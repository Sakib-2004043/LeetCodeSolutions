class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i, n, mx,ans;
        unordered_map<int, int> count;
        n = nums.size();
        mx = 0;
        for (i = 0; i < n; i++) {
            count[nums[i]]++;
            if(mx<count[nums[i]]){
                ans = nums[i];
                mx = count[nums[i]];
            }
        }
        return ans;
    }
};