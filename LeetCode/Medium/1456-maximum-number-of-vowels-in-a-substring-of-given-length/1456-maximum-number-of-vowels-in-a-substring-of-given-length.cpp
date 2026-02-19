class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size(), count = 0, mx = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < n; i++) {
            count += vowels.count(s[i]) ? 1 : 0;
            count -= i >= k && vowels.count(s[i - k]) ? 1 : 0;
            mx = max(mx, count);
        }
        return mx;
    }
};