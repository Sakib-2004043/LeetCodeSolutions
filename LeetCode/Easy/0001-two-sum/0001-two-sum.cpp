class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, n;
        unordered_map<int, bool> valFind;
        unordered_map<int, int> index;
        vector<int> retVec;

        n = nums.size();
        for (i = 0; i < n; i++) {
            int find = target - nums[i];
            if (valFind[find]) {
                retVec.push_back(index[find]);
                retVec.push_back(i);
                return retVec;
            }
            valFind[nums[i]] = true;
            index[nums[i]] = i;
        }
        return retVec;
    }
};