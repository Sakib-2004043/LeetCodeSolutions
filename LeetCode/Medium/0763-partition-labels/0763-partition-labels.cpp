class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> last(26);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }
        int i = 0;
        while (i < n) {
            int start = i;
            int mx = last[s[i] - 'a'];
            while (i <= mx) {
                mx = max(mx, last[s[i] - 'a']);
                i++;
            }
            ans.push_back(i - start);
        }
        return ans;
    }
};
