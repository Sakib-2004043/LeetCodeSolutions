class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> v;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.rbegin(), v.rend());
        long long sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            minHeap.push(v[i].second);
            sum += v[i].second;
            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == k) {
                ans = max(ans, sum * 1LL * v[i].first);
            }
        }
        return ans;
    }
};
