unordered_map<char, string> dtc = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                   {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                   {'8', "tuv"}, {'9', "wxyz"}};

class Solution {
public:
    vector<string> combine(const vector<string>& prev, const string& letters) {
        vector<string> result;
        if (prev.empty()) {
            for (char c : letters) {
                result.push_back(string(1, c));
            }
            return result;
        }
        for (const string& s : prev) {
            for (char c : letters) {
                result.push_back(s + c);
            }
        }
        return result;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty())
            return ans;
        for (char d : digits) {
            ans = combine(ans, dtc[d]);
        }
        return ans;
    }
};
