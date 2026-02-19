class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    int maxVowels(string s, int k) {
        int n = s.size(), count = 0, mx = 0;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < n; i++) {
            count += isVowel(s[i]) ? 1 : 0;
            count -= i >= k && isVowel(s[i - k]) ? 1 : 0;
            mx = max(mx, count);
        }
        return mx;
    }
};