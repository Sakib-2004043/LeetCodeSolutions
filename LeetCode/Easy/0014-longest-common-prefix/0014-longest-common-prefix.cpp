class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // If array is empty, return ""
        if (strs.size() == 0) return "";

        // Take first string as prefix
        string prefix = strs[0];

        // Compare prefix with each string
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;

            // Compare characters
            while (j < prefix.length() && j < strs[i].length()
                   && prefix[j] == strs[i][j]) {
                j++;
            }

            // Reduce prefix
            prefix = prefix.substr(0, j);

            // If prefix becomes empty, no common prefix exists
            if (prefix == "") return "";
        }

        return prefix;
    }
};
