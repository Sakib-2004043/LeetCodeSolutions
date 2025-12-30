class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineLen = 0;
            int start = i;

            // Step 1: pack as many words as possible in the line
            while (i < n && lineLen + words[i].size() + (i - start) <= maxWidth) {
                lineLen += words[i].size();
                i++;
            }

            int wordCount = i - start;
            int spaceCount = wordCount - 1;
            string line;

            // Step 2: last line OR single word → left justified
            if (i == n || spaceCount == 0) {
                for (int j = start; j < i; j++) {
                    line += words[j];
                    if (j < i - 1) line += " ";
                }
                line += string(maxWidth - line.size(), ' ');
            }
            // Step 3: fully justified line
            else {
                int totalSpaces = maxWidth - lineLen;
                int minSpace = totalSpaces / spaceCount;
                int extraSpace = totalSpaces % spaceCount;
                for (int j = start; j < i; j++) {
                    line += words[j];
                    if (j < i - 1) {
                        line += string(minSpace, ' ');
                        if (extraSpace-- > 0) line += " ";
                    }
                }
            }
            result.push_back(line);
        }
        return result;
    }
};
