class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        int i, n, gap, k, row;
        string ans = "";
        n = s.size();
        gap = numRows * 2 - 2;
        k = gap;
        for (row = 0; row < numRows; row++) {
            for (i = row; i < n; i += gap) {
                ans += s[i];
                if (i + k < n && row != 0 && row != numRows - 1) {
                    ans += s[i + k];
                }
            }
            k -= 2;
        }
        return ans;
    }
};