class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i, sum, ans;
        vector<int> suffix_sum;
        sum = 0;
        for (i = 0; i < gas.size(); i++) {
            // cout << gas[i] - cost[i] << " ";
            suffix_sum.push_back(gas[i] - cost[i]);
            sum += (gas[i] - cost[i]);
        }
        for (i = gas.size() - 2; i >= 0; i--) {
            suffix_sum[i] += suffix_sum[i + 1];
        }
        ans = max_element(suffix_sum.begin(), suffix_sum.end()) -
              suffix_sum.begin();
        return sum >= 0 ? ans : -1;
    }
};