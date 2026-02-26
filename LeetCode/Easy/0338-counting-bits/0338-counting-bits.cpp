class Solution {
public:
    int popCount(int num) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            count += num >> i & 1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            ans.push_back(popCount(i));
        }
        return ans;
    }
};