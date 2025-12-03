class Solution {
public:
    int hammingWeight(int n) {
        int i, ans;
        ans=0;
        for(i=0;i<32;i++){
            if(n&1){
                ans++;
            }
            n >>= 1;
        }
        return ans;
    }
};