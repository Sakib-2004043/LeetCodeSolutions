class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        vector<int> ans;
        int sn = spells.size();
        int pn = potions.size();
        sort(potions.begin(), potions.end());
        for (int i = 0; i < sn; i++) {
            int left = 0;
            int right = pn - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                long long score = long(potions[mid]) * long(spells[i]);
                if (score < success) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            ans.push_back(pn - left);
        }
        return ans;
    }
};