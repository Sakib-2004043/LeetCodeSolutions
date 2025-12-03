class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i,n,ans;
        n=nums.size();
        ans=0;
        for(i=0;i<n;i++){
            ans ^= nums[i];
        }
        return ans;
    }
};