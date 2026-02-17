class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                for (int k = 0; k < n; k++) {
                    int num = digits[i] * 100;
                    num += (digits[j] * 10 + digits[k]);
                    if (j != k && i != k && num % 2 == 0 && num > 99) {
                        ans.insert(num);
                    }
                }
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};