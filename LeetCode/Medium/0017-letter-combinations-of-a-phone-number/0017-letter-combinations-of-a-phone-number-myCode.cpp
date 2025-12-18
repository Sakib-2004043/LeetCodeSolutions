unordered_map<char, string> dtc = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                   {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                   {'8', "tuv"}, {'9', "wxyz"}};

class Solution {
public:
    vector<string> latter_add(vector<string>& ans, string latters) {
        int i, j;
        vector<string> newAns;
        if (ans.size() == 0) {
            for (j = 0; j < latters.size(); j++) {
                newAns.push_back(string(1, latters[j]));
            }
            return newAns;
        }
        for (i = 0; i < ans.size(); i++) {
            for (j = 0; j < latters.size(); j++) {
                newAns.push_back(ans[i] + latters[j]);
            }
        }
        return newAns;
    }
    vector<string> letterCombinations(string digits) {
        int i, n;
        vector<string> ans;
        n = digits.size();
        for (i = 0; i < n; i++) {
            ans = latter_add(ans, dtc[digits[i]]);
        }
        return ans;
    }
};