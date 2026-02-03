class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        bool k = false;
        while (i < n && nums[i - 1] < nums[i]) {
            i++;
            k = true;
        }
        if (!k) {
            return k;
        }
        k = false;
        while (i < n && nums[i - 1] > nums[i]) {
            i++;
            k = true;
        }
        if (!k) {
            return k;
        }
        k = false;
        while (i < n && nums[i - 1] < nums[i]) {
            i++;
            k = true;
        }
        if (!k || i!=n) {
            return false;
        }
        return true;
    }
};