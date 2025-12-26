class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int i, n;
        unordered_map<string, vector<string>> angm;
        vector<vector<string>> ans;
        n = strs.size();
        for (i = 0; i < n; i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            angm[temp].push_back(strs[i]);
        }
        for (auto v : angm) {
            ans.push_back(v.second);
        }
        return ans;
    }
};