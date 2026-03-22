class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int n = s.size();
        int i = 0, last = 0;
        while (i < n) {
            int mx = i;
            while (i <= mx) {
                int pos = s.find(s[i], i + 1);
                mx = max(mx, pos);
                i++;
            }
            ans.push_back(i - last);
            last = i;
        }
        return ans;
    }
};