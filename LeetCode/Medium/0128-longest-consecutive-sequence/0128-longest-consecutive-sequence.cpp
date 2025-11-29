class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()){
            return 0;
        }
        int i, n, ans, prev, now, counter;
        ans = 0;
        map<int, bool> numCheck;

        n = nums.size();

        for (i = 0; i < n; i++) {
            numCheck[nums[i]] = true;
        }
        prev = *min_element(nums.begin(), nums.end());
        counter = 0;
        for (auto x : numCheck) {
            now = x.first;
            if ((now - prev) <= 1) {
                counter += 1;
            } else {
                ans = max(ans, counter);
                counter = 1;
            }
            // cout << x.first << " " << x.second << endl;
            // cout << "Now : " << now << " " << "Prev : " << prev << endl;
            prev = x.first;
        }
        ans = max(ans, counter);
        return ans;
    }
};