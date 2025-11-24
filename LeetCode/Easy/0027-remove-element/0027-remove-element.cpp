#include<bits/stdc++.h>
typedef long long lli;
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        lli n,i,k=0;
        n=nums.size();

        for(i=0;i<n;i++){
            if(nums[i]!=val){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};