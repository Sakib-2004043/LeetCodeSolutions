class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> freqP(26), window(26);
        for (auto c : p) {
            freqP[c - 'a']++;
        }
        int n = s.size();
        int k = p.size();
        for (int i = 0; i < n; i++) {
            window[s[i] - 'a']++;
            if (i >= k) {
                window[s[i - k] - 'a']--;
            }
            if (freqP == window) {
                ans.push_back(i - k + 1);
            }
        }
        return ans;
    }
};