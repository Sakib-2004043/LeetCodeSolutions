class Solution {
public:
    string removeStars(string s) {
        while (true) {
            int idx = s.find('*');
            if (idx == -1) {
                break;
            }
            s.erase(idx - 1, 2);
        }
        return s;
    }
};