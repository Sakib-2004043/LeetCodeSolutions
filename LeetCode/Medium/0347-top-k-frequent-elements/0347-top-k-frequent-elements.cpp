class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> ans;
        using T = tuple<int, int>;
        priority_queue<T, vector<T>, less<T>> maxHeap;
        for (auto num : nums) {
            freq[num]++;
        }
        for (auto [x, y] : freq) {
            maxHeap.push({y, x});
        }
        for (int i = 0; i < k; i++) {
            ans.push_back(get<1>(maxHeap.top()));
            maxHeap.pop();
        }
        return ans;
    }
};