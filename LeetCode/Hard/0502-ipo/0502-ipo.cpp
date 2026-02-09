class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        using T = tuple<int, int>;
        priority_queue<T, vector<T>, greater<T>> minPQ;
        priority_queue<T, vector<T>, less<T>> maxPQ;
        int n = profits.size();
        for (int i = 0; i < n; i++) {
            if (capital[i] <= w) {
                maxPQ.push({profits[i], capital[i]});
            } else {
                minPQ.push({capital[i], -profits[i]});
            }
        }
        int ans = w;
        while (k--) {
            if (maxPQ.empty()) {
                return ans;
            }
            auto [p, c] = maxPQ.top();
            maxPQ.pop();
            ans += p;
            w += p;
            while (!minPQ.empty() && get<0>(minPQ.top()) <= w) {
                auto [nc, np] = minPQ.top();
                minPQ.pop();
                maxPQ.push({-np, nc});
            }
        }
        return ans;
    }
};
/*
Input
k = 1
w = 2
profits = [1,2,3]
capital = [1,1,2]
Output = 3
Expected = 5
Still Why ???
*/
