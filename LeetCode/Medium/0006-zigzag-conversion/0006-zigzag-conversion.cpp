class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) {
            return s;
        }
        int n = s.size();
        int cycle = 2 * numRows - 2;
        string result;
        for (int row = 0; row < numRows; row++) {
            for (int i = row; i < n; i += cycle) {
                result += s[i];
                int diagonal = i + cycle - 2 * row;
                if (row != 0 && row != numRows - 1 && diagonal < n) {
                    result += s[diagonal];
                }
            }
        }
        return result;
    }
};
