class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (dq.front() + k <= i) {
                dq.pop_front();
            }
            if (k <= i + 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};