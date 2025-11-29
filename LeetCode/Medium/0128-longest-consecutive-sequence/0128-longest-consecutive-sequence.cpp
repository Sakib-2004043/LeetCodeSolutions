class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()){
            return 0;
        }
        int i, n, ans, prev, now, counter;
        ans = 0;
        set<int> numCheck;

        n = nums.size();

        prev = pow(10,9)+5; 
        for (i = 0; i < n; i++) {
            numCheck.insert(nums[i]);
            prev = min (prev, nums[i]);
        }
        counter = 0;
        for (auto x : numCheck) {
            now = x;
            if ((now - prev) <= 1) {
                counter += 1;
            } else {
                ans = max(ans, counter);
                counter = 1;
            }
            // cout << x.first << " " << x.second << endl;
            // cout << "Now : " << now << " " << "Prev : " << prev << endl;
            prev = x;
        }
        ans = max(ans, counter);
        return ans;
    }
};