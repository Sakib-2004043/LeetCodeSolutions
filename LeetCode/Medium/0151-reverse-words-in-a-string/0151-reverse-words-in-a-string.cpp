class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.size(), i = 0;

        while (i < n) {
            // Skip spaces
            while (i < n && isspace(s[i]))
                i++;
            if (i >= n)
                break;

            // Collect a word
            int j = i;
            while (j < n && !isspace(s[j]))
                j++;
            words.push_back(s.substr(i, j - i));
            i = j;
        }

        // Build reversed string
        string ans = "";
        for (int k = words.size() - 1; k >= 0; k--) {
            ans += words[k];
            if (k != 0)
                ans += " ";
        }

        return ans;
    }
};
