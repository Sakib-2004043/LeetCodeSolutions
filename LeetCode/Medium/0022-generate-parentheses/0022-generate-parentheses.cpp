class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int i;
        string par;
        vector<string> ans;
        for (i = 0; i < n; i++) {
            par = "("+par+")";
        }
        do {
            int left = 0, right = 0, flag = 1;
            for (i = 0; i < n * 2; i++) {
                if (par[i] == '(')
                    left++;
                else
                    right++;
                if (left < right)
                    flag = 0;
            }
            if (flag)
                ans.push_back(par);
            cout<<par<<endl;
        } while (next_permutation(par.begin(), par.end()));
        return ans;
    }
};