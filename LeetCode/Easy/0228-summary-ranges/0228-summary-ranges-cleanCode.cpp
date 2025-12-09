class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i, n, k;
        vector<string> ret;
        n = nums.size();
        for (i = 0, k = 0; i < n; i++) {
            string temp = to_string(nums[i]);
            while (i + 1 < n && nums[i] + 1 == nums[i + 1]) {
                i++;
                k = 1;
            }
            if (k) {
                temp += "->";
                temp += to_string(nums[i]);
                k = 0;
            }
            // cout<<temp<<endl;
            ret.push_back(temp);
        }
        return ret;
    }
};