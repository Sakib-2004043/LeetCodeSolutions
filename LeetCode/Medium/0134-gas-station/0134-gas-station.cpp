class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum, ans, mx, n;
        vector<int> suffix_sum;
        n = gas.size();
        sum = 0;
        for (int i = 0; i < n; i++) {
            // cout << gas[i] - cost[i] << " ";
            suffix_sum.push_back(gas[i] - cost[i]);
            sum += (gas[i] - cost[i]);
        }
        if (sum < 0) {
            return -1;
        }
        mx = suffix_sum[n - 1];
        ans = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            suffix_sum[i] += suffix_sum[i + 1];
            if (suffix_sum[i] >= mx) {
                mx = suffix_sum[i];
                ans = i;
            }
        }
        return ans;
    }
};