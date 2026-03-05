class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pqL, pqR;
        int i = 0, j = costs.size() - 1;
        for (int c = 0; c < candidates && i <= j; c++) {
            pqL.push(costs[i++]);
        }
        for (int c = 0; c < candidates && i <= j; c++) {
            pqR.push(costs[j--]);
        }
        long long ans = 0;
        while (k--) {
            if (pqR.empty() || (!pqL.empty() && pqL.top() <= pqR.top())) {
                ans += pqL.top();
                pqL.pop();
                if (i <= j) {
                    pqL.push(costs[i++]);
                }
            } else {
                ans += pqR.top();
                pqR.pop();
                if (i <= j) {
                    pqR.push(costs[j--]);
                }
            }
        }
        return ans;
    }
};
