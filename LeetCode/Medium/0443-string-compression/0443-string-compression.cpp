class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), k = 0;
        for (int i = 0; i < n; i++) {
            chars[k++] = chars[i];
            int count = 0;
            for (int j = i; j < n && chars[i] == chars[j]; j++) {
                count++;
                i = j;
            }
            if (count == 1) {
                continue;
            }
            string num = to_string(count);
            for (int j = 0; j < num.size(); j++) {
                chars[k++] = num[j];
            }
        }
        return k;
    }
};