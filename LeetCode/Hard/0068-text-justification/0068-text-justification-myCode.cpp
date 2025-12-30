class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n; ) {
            vector<string> wordRow;
            int rowLen = 0, wordLen = 0;
            while (i < n && rowLen + words[i].size() <= maxWidth) {
                wordRow.push_back(words[i]);
                rowLen += words[i].size();
                wordLen += words[i].size();
                rowLen += rowLen != maxWidth ? 1 : 0;
                i++;
            }
            int spaceCount = wordRow.size() - 1;
            int extraSpace = maxWidth - wordLen;
            int minSpace = spaceCount ? extraSpace / spaceCount : 0;
            int remainSpace = minSpace ? extraSpace % spaceCount : 0;
            string temp = "";
            if(i==n){
                minSpace = 1;
                remainSpace = 0;
            }
            for (int j = 0; j < wordRow.size(); j++) {
                temp += wordRow[j];
                if (j < wordRow.size() - 1) {
                    for (int k = 0; k < minSpace; k++) {
                        temp += " ";
                    }
                    if (remainSpace) {
                        temp += " ";
                        remainSpace--;
                    }
                }
            }
            while(temp.size()<maxWidth){
                temp+=" ";
            }
            ans.push_back(temp);
        }
        return ans;
    }
};