class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans, sub = "";
        int n = str1.size();
        for (int i = 0; i < n; i++) {
            sub += str1[i];
            int pos1 = 0, count1 = 0;
            while ((pos1 = str1.find(sub, pos1)) != string::npos) {
                count1++;
                pos1 += sub.length();
            }
            if (count1 * sub.size() != str1.size()) {
                continue;
            }
            int pos2 = 0, count2 = 0;
            while ((pos2 = str2.find(sub, pos2)) != string::npos) {
                count2++;
                pos2 += sub.length();
            }
            if (count2 * sub.size() != str2.size()) {
                continue;
            }
            ans = sub;
        }
        return ans;
    }
};